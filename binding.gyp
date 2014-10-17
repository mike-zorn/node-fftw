{
  "targets": [
    {
      "target_name": "fftw",
      "sources": [ 
        "src/fftw.cc" 
      , "src/complex.cc"
      , "src/fft_worker.cc"
      , "src/fft_worker_1d.cc"
      , "src/ifft_worker_1d.cc"
      ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ],
      "dependencies" : [
        "<(module_root_dir)/deps/fftw3.gyp:fftw3"
      ]
    }
  ]
}
