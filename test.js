var fftw = require('./index');
var test = require('tape');
var async = require('async');
var noop = require('lodash.noop');

test('1d dft all ones', function(t) {
  t.plan(10);
  fftw.plan_dft_1d({ size: 4 }, function(err, plan) {
    t.error(err);
    plan.execute([1, 1, 1, 1], function(err, result) {
      t.error(err);
      t.equal(result[0].real, 4);
      t.equal(result[0].imag, 0);
      t.equal(result[1].real, 0);
      t.equal(result[1].imag, 0);
      t.equal(result[2].real, 0);
      t.equal(result[2].imag, 0);
      t.equal(result[3].real, 0);
      t.equal(result[3].imag, 0);
    });
  });
});

test('1d dft all ones with reused plan', function(t) {
  t.plan(11);
  fftw.plan_dft_1d({ 
    size: 4,
    rigor: 'patient'
  }, function(err, plan) {
    t.error(err);
    plan.execute([1, 1, 1, 1], function(err, result, plan) {
      t.error(err);
      plan.execute([1, 1, 1, 1], function(err, result, plan) {
        t.error(err);
        t.equal(result[0].real, 4);
        t.equal(result[0].imag, 0);
        t.equal(result[1].real, 0);
        t.equal(result[1].imag, 0);
        t.equal(result[2].real, 0);
        t.equal(result[2].imag, 0);
        t.equal(result[3].real, 0);
        t.equal(result[3].imag, 0);
      });
    });
  });
});

test('1d idft one 1', function(t) {
  t.plan(10);

  fftw.plan_dft_1d({ 
    size: 4, 
    sign: 'backward'
  }, function(err, plan) {
    t.error(err);
    plan.execute([1, 0, 0, 0], function(err, result) {
      t.error(err);
      result.forEach(function(complex) {
        t.equal(complex.real, 1);
        t.equal(complex.imag, 0);
      });
    });
  });
});

test('1d forward reverse all ones', function(t) {
  t.plan(11);
  
  async.map(
    [{ size: 4, sign: 'forward' }, { size: 4, sign: 'backward' }],
    fftw.plan_dft_1d, 
    function(err, plans) {
      t.error(err);
      plans[0].execute([1, 1, 1, 1], function(err, result) {
        t.error(err);
        plans[1].execute(result, function(err, result) {
          t.error(err);
          result.forEach(function(complex) {
            t.equal(complex.real, 4);
            t.equal(complex.imag, 0);
          });
        });
      });
    }
  );
});

test('should throw RangeError for invalid sign', function(t) {
  t.plan(1);
  t.throws(
    fftw.plan_dft_1d.bind(fftw, { size: 5, sign: 'dasdsa' }, noop),
    /sign must be one of backward or forward/);
});

test('should throw RangeError for invalid rigor', function(t) {
  t.plan(1);
  t.throws(
    fftw.plan_dft_1d.bind(fftw, { size: 5, rigor: 'dasdsa' }, noop),
    /sign must be one of estimate, measure, patient or exhaustive/);
});

test('should throw when plan is executed multiple times', function(t) {
  t.plan(1);
  fftw.plan_dft_1d( { size: 5 }, function(err, plan) {
    t.throws(function() {
      plan.execute([1, 1, 1, 1, 1], noop);
      plan.execute([1, 1, 1, 1, 1], noop);
    }, /plan may only be executed once/);
  });
});
