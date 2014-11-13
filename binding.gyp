{
  "targets": [
    {
      "target_name": "fftw",
      "sources": [ 
        "src/fftw.cc" 
      , "src/complex.cc"
      , "src/plan.cc"
      , "src/planner_dft_1d.cc"
      , "src/executor.cc"
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
