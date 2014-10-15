var fftw = require('./index');
var test = require('tape');

test('1d dft all ones', function(t) {
  t.plan(1);

  fftw.dft_1d([1, 1, 1, 1], function(err, result) {
    t.equal(result[0].real, 4);
  });
});

test('1d idft one 1', function(t) {
  t.plan(2);

  fftw.idft_1d([1, 0, 0, 0], function(err, result) {
    t.equal(result[0].real, 1);
    t.equal(result[2].real, 1);
  });
});

test('1d forward reverse all ones', function(t) {
  t.plan(8);
  fftw.dft_1d([1, 1, 1, 1], function(err, result) {
    fftw.idft_1d(result, function(err, result) {
      result.forEach(function(complex) {
        t.equal(complex.real, 1);
        t.equal(complex.imag, 0);
      });
    });
  });
});
