FFTW for node.js
================

The fastest fourier transform in the west for node.js

Installation
------------
`npm install`

Usage
-----
```javascript
fftw.dft_1d([1, 1, 1, 1], function(err, result) {
  result.forEach(function(complex) {
    console.log(complex.toString());
  });
});
```
yields `4 + 0i 0 + 0i 0 + 0i 0 + 0i`. Note that each complex object has the
accessors, `real` and `imag` exposed for accessing the real and imaginary
parts, respectively. Complex input may also be used.
```javascript
var input = [
  { real: 1, imag: 1 },
  { real: 1, imag: 1 },
  { real: 1, imag: 1 },
  { real: 1, imag: 1 }
];

fftw.dft_1d(input, function(err, result) {
  result.forEach(function(complex) {
    console.log(complex.toString());
  });
});
```

The following transforms are currently exposed.
  * `dft_1d`
  * `idft_1d`

Planned features
----------------

1. Expose plan API
  - Expose the API
  - deprecate the current API
  - create another module to provide the current API by handling plans
    automatically
2. Support higher dimensional transforms
3. Support all the other FFTW transform types
