var fftw = require('./index');
var test = require('tape');

test('1d dft all ones', function(t) {
  t.plan(1);

  fftw.dft_1d([1, 1, 1, 1], function(err, result) {
    t.equal(result[0].real, 4);
  });
});
