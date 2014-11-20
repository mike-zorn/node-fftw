FFTW for node.js
================

[![Build Status](https://travis-ci.org/apechimp/node-fftw.png?branch=master)]
(https://travis-ci.org/apechimp/node-fftw)

The fastest fourier transform in the west for node.js. The goal of this module
is to provide the closest possible API to 
[FFTW](http://www.fftw.org/fftw3_doc/) in javascript.

Installation
------------

[![npm install fftw](https://nodei.co/npm/fftw.png)](https://npmjs.org/package/fftw)

Usage
-----

Create a plan and execute that plan.
```javascript
fftw.plan_dft_1d({ size: 4 }, function(err, plan) {
  plan.execute([1, 1, 1, 1], function(err, result) {
    console.log(result);
  });
});
```
yields `4 + 0i 0 + 0i 0 + 0i 0 + 0i`. Note that each complex object has the
accessors, `real` and `imag` exposed for accessing the real and imaginary
parts, respectively. Complex input may also be used.
```javascript
fftw.plan_dft_1d({ size: 4 }, function(err, plan) {
  plan.execute([1, 1, 1, 1], function(err, result, plan) {
    plan.execute(result, function(err, result) {
      console.log(result);
    });
  });
});
```
Note that a given plan may be only used one time, but a new plan is provided in
the execute callback. This is to alleviate potential concurrency issues.
