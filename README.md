FFTW for node.js
================

Linux Build | Windows Build
------------|--------------|
[![Build Status](https://travis-ci.org/apechimp/node-fftw.svg?branch=master)](https://travis-ci.org/apechimp/node-fftw) |[![Build status](https://ci.appveyor.com/api/projects/status/8u6ghatt9gkvj5go/branch/master?svg=true)](https://ci.appveyor.com/project/apechimp/node-fftw/branch/master)

The fastest fourier transform in the west for node.js

Installation
------------

[![npm install fftw](https://nodei.co/npm/fftw.png)](https://npmjs.org/package/fftw)

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
