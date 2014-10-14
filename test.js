var fftw = require('./index');

fftw.dft_1d([1, 1, 1, 1], function(err, vals) {
  vals.forEach(function(val) {
    console.log(val.real, val.imag);
  });
});
