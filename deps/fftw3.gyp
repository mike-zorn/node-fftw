{
  'variables': {
    'fftwversion': '3.3.4'
  }, 
  {
    'target_name': 'reodft', 
    'type': 'static_library',
    'include_dirs': [
      'config/<(OS)'
    ],
    'direct_dependent_settings': {
      'include_dirs': [
        'fftw-<(fftwversion)/kernel'
      ]
    },
    'sources': [
    ]
  },
  {
    'target_name': 'rdft.scalar.r2r', 
    'type': 'static_library',
    'include_dirs': [
      'config/<(OS)'
    ],
    'direct_dependent_settings': {
      'include_dirs': [
        'fftw-<(fftwversion)/kernel'
      ]
    },
    'sources': [
    ]
  },
  {
    'target_name': 'rdft.scalar.r2cb', 
    'type': 'static_library',
    'include_dirs': [
      'config/<(OS)'
    ],
    'direct_dependent_settings': {
      'include_dirs': [
        'fftw-<(fftwversion)/kernel'
      ]
    },
    'sources': [
    ]
  },
  {
    'target_name': 'rdft.scalar.r2cf', 
    'type': 'static_library',
    'include_dirs': [
      'config/<(OS)'
    ],
    'direct_dependent_settings': {
      'include_dirs': [
        'fftw-<(fftwversion)/kernel'
      ]
    },
    'sources': [
    ]
  },
  {
    'target_name': 'rdft.scalar', 
    'type': 'static_library',
    'include_dirs': [
      'config/<(OS)'
    ],
    'direct_dependent_settings': {
      'include_dirs': [
        'fftw-<(fftwversion)/kernel'
      ]
    },
    'sources': [
    ]
  },
  {
    'target_name': 'rdft', 
    'type': 'static_library',
    'include_dirs': [
      'config/<(OS)'
    ],
    'direct_dependent_settings': {
      'include_dirs': [
        'fftw-<(fftwversion)/kernel'
      ]
    },
    'sources': [
    ]
  },
  {
    'target_name': 'dft.scalar.codelets', 
    'type': 'static_library',
    'include_dirs': [
      'config/<(OS)'
    ],
    'direct_dependent_settings': {
      'include_dirs': [
        'fftw-<(fftwversion)/kernel'
      ]
    },
    'sources': [
    ]
  },
  {
    'target_name': 'dft.scalar', 
    'type': 'static_library',
    'include_dirs': [
      'config/<(OS)'
    ],
    'direct_dependent_settings': {
      'include_dirs': [
        'fftw-<(fftwversion)/kernel'
      ]
    },
    'sources': [
    ]
  },
  {
    'target_name': 'dft', 
    'type': 'static_library',
    'include_dirs': [
      'config/<(OS)'
    ],
    'direct_dependent_settings': {
      'include_dirs': [
        'fftw-<(fftwversion)/kernel'
      ]
    },
    'sources': [
    ]
  },
  {
    'target_name': 'simd-support', 
    'type': 'static_library',
    'include_dirs': [
      'config/<(OS)'
    ],
    'direct_dependent_settings': {
      'include_dirs': [
        'fftw-<(fftwversion)/kernel'
      ]
    },
    'sources': [
    ]
  },
  'targets': [
  {
    'target_name': 'kernel', 
    'type': 'static_library',
    'include_dirs': [
      'config/<(OS)'
    ],
    'direct_dependent_settings': {
      'include_dirs': [
        'fftw-<(fftwversion)/kernel'
      ]
    },
    'sources': [
      'fftw-<(fftwversion)/kernel/align.c',
      'fftw-<(fftwversion)/kernel/alloc.c',
      'fftw-<(fftwversion)/kernel/assert.c',
      'fftw-<(fftwversion)/kernel/awake.c',
      'fftw-<(fftwversion)/kernel/buffered.c',
      'fftw-<(fftwversion)/kernel/cpy1d.c',
      'fftw-<(fftwversion)/kernel/cpy2d-pair.c',
      'fftw-<(fftwversion)/kernel/cpy2d.c',
      'fftw-<(fftwversion)/kernel/ct.c',
      'fftw-<(fftwversion)/kernel/debug.c',
      'fftw-<(fftwversion)/kernel/extract-reim.c',
      'fftw-<(fftwversion)/kernel/hash.c',
      'fftw-<(fftwversion)/kernel/iabs.c',
      'fftw-<(fftwversion)/kernel/kalloc.c',
      'fftw-<(fftwversion)/kernel/md5-1.c',
      'fftw-<(fftwversion)/kernel/md5.c',
      'fftw-<(fftwversion)/kernel/minmax.c',
      'fftw-<(fftwversion)/kernel/ops.c',
      'fftw-<(fftwversion)/kernel/pickdim.c',
      'fftw-<(fftwversion)/kernel/plan.c',
      'fftw-<(fftwversion)/kernel/planner.c',
      'fftw-<(fftwversion)/kernel/primes.c',
      'fftw-<(fftwversion)/kernel/print.c',
      'fftw-<(fftwversion)/kernel/problem.c',
      'fftw-<(fftwversion)/kernel/rader.c',
      'fftw-<(fftwversion)/kernel/scan.c',
      'fftw-<(fftwversion)/kernel/solver.c',
      'fftw-<(fftwversion)/kernel/solvtab.c',
      'fftw-<(fftwversion)/kernel/stride.c',
      'fftw-<(fftwversion)/kernel/tensor.c',
      'fftw-<(fftwversion)/kernel/tensor1.c',
      'fftw-<(fftwversion)/kernel/tensor2.c',
      'fftw-<(fftwversion)/kernel/tensor3.c',
      'fftw-<(fftwversion)/kernel/tensor4.c',
      'fftw-<(fftwversion)/kernel/tensor5.c',
      'fftw-<(fftwversion)/kernel/tensor7.c',
      'fftw-<(fftwversion)/kernel/tensor8.c',
      'fftw-<(fftwversion)/kernel/tensor9.c',
      'fftw-<(fftwversion)/kernel/tile2d.c',
      'fftw-<(fftwversion)/kernel/timer.c',
      'fftw-<(fftwversion)/kernel/transpose.c',
      'fftw-<(fftwversion)/kernel/trig.c',
      'fftw-<(fftwversion)/kernel/twiddle.c',
      'fftw-<(fftwversion)/kernel/cycle.h',
      'fftw-<(fftwversion)/kernel/ifftw.h'
    ]
  },
  {
    'target_name': 'dft', 
    'type': 'static_library',
    'include_dirs': [
      'config/<(OS)',
      'fftw-<(fftwversion)/kernel',
      'fftw-<(fftwversion)/dft'
    ],
    'direct_dependent_settings': {
      'include_dirs': [
        'fftw-<(fftwversion)/dft'
      ]
    },
    'sources': [
      'fftw-<(fftwversion)/dft/bluestein.c',
      'fftw-<(fftwversion)/dft/buffered.c',
      'fftw-<(fftwversion)/dft/conf.c',
      'fftw-<(fftwversion)/dft/ct.c',
      'fftw-<(fftwversion)/dft/dftw-direct.c',
      'fftw-<(fftwversion)/dft/dftw-directsq.c',
      'fftw-<(fftwversion)/dft/dftw-generic.c',
      'fftw-<(fftwversion)/dft/dftw-genericbuf.c',
      'fftw-<(fftwversion)/dft/direct.c',
      'fftw-<(fftwversion)/dft/generic.c',
      'fftw-<(fftwversion)/dft/indirect.c',
      'fftw-<(fftwversion)/dft/indirect-transpose.c',
      'fftw-<(fftwversion)/dft/kdft-dif.c',
      'fftw-<(fftwversion)/dft/kdft-difsq.c',
      'fftw-<(fftwversion)/dft/kdft-dit.c',
      'fftw-<(fftwversion)/dft/kdft.c',
      'fftw-<(fftwversion)/dft/nop.c',
      'fftw-<(fftwversion)/dft/plan.c',
      'fftw-<(fftwversion)/dft/problem.c',
      'fftw-<(fftwversion)/dft/rader.c',
      'fftw-<(fftwversion)/dft/rank-geq2.c',
      'fftw-<(fftwversion)/dft/solve.c',
      'fftw-<(fftwversion)/dft/vrank-geq1.c',
      'fftw-<(fftwversion)/dft/zero.c',
      'fftw-<(fftwversion)/dft/codelet-dft.h',
      'fftw-<(fftwversion)/dft/ct.h',
      'fftw-<(fftwversion)/dft/dft.h'
    ]
  }
, {
    'target_name': 'fftw3'
  , 'type': 'static_library'
  , 'include_dirs': [
      'config/<(OS)'
        'fftw-<(fftwversion)/api'
      , 'fftw-<(fftwversion)/kernel'
      , 'fftw-<(fftwversion)/rdft'
      , 'fftw-<(fftwversion)/dft'
      , 'fftw-<(fftwversion)/reodft'
      , 'fftw-<(fftwversion)'
    ]
  , 'direct_dependent_settings': {
      'include_dirs': [
        'fftw-<(fftwversion)/api'
      , 'fftw-<(fftwversion)/kernel'
      , 'fftw-<(fftwversion)/rdft'
      , 'fftw-<(fftwversion)/dft'
      , 'fftw-<(fftwversion)/reodft'
      , 'fftw-<(fftwversion)'
      ]
    },
    'dependencies' : [
      '<(module_root_dir)/deps/fftw3.gyp:kernel',
      '<(module_root_dir)/deps/fftw3.gyp:dft',
      '<(module_root_dir)/deps/fftw3.gyp:rdft',
      '<(module_root_dir)/deps/fftw3.gyp:reodft',
      '<(module_root_dir)/deps/fftw3.gyp:simd-support'
    ]
  , 'sources': [
      'fftw-<(fftwversion)/api/fftw3.h'
    , 'fftw-<(fftwversion)/api/apiplan.c'
    , 'fftw-<(fftwversion)/api/configure.c'
    , 'fftw-<(fftwversion)/api/execute-dft-c2r.c'		
    , 'fftw-<(fftwversion)/api/execute-dft-r2c.c'
    , 'fftw-<(fftwversion)/api/execute-dft.c'
    , 'fftw-<(fftwversion)/api/execute-r2r.c'
    , 'fftw-<(fftwversion)/api/execute-split-dft-c2r.c'	
    , 'fftw-<(fftwversion)/api/execute-split-dft-r2c.c'
    , 'fftw-<(fftwversion)/api/execute-split-dft.c'
    , 'fftw-<(fftwversion)/api/execute.c'			
    , 'fftw-<(fftwversion)/api/export-wisdom-to-file.c'
    , 'fftw-<(fftwversion)/api/export-wisdom-to-string.c'
    , 'fftw-<(fftwversion)/api/export-wisdom.c'	
    , 'fftw-<(fftwversion)/api/f77api.c'
    , 'fftw-<(fftwversion)/api/flops.c'
    , 'fftw-<(fftwversion)/api/forget-wisdom.c'
    , 'fftw-<(fftwversion)/api/import-system-wisdom.c'			
    , 'fftw-<(fftwversion)/api/import-wisdom-from-file.c'
    , 'fftw-<(fftwversion)/api/import-wisdom-from-string.c'
    , 'fftw-<(fftwversion)/api/import-wisdom.c'	
    , 'fftw-<(fftwversion)/api/malloc.c'
    , 'fftw-<(fftwversion)/api/map-r2r-kind.c'
    , 'fftw-<(fftwversion)/api/mapflags.c'
    , 'fftw-<(fftwversion)/api/mkprinter-file.c'
    , 'fftw-<(fftwversion)/api/mkprinter-str.c'	
    , 'fftw-<(fftwversion)/api/mktensor-iodims.c'
    , 'fftw-<(fftwversion)/api/mktensor-rowmajor.c'
    , 'fftw-<(fftwversion)/api/plan-dft-1d.c'
    , 'fftw-<(fftwversion)/api/plan-dft-2d.c'	
    , 'fftw-<(fftwversion)/api/plan-dft-3d.c'
    , 'fftw-<(fftwversion)/api/plan-dft-c2r-1d.c'
    , 'fftw-<(fftwversion)/api/plan-dft-c2r-2d.c'
    , 'fftw-<(fftwversion)/api/plan-dft-c2r-3d.c'	
    , 'fftw-<(fftwversion)/api/plan-dft-c2r.c'
    , 'fftw-<(fftwversion)/api/plan-dft-r2c-1d.c'
    , 'fftw-<(fftwversion)/api/plan-dft-r2c-2d.c'
    , 'fftw-<(fftwversion)/api/plan-dft-r2c-3d.c'	
    , 'fftw-<(fftwversion)/api/plan-dft-r2c.c'
    , 'fftw-<(fftwversion)/api/plan-dft.c'
    , 'fftw-<(fftwversion)/api/plan-guru-dft-c2r.c'
    , 'fftw-<(fftwversion)/api/plan-guru-dft-r2c.c'	
    , 'fftw-<(fftwversion)/api/plan-guru-dft.c'
    , 'fftw-<(fftwversion)/api/plan-guru-r2r.c'
    , 'fftw-<(fftwversion)/api/plan-guru-split-dft-c2r.c'		
    , 'fftw-<(fftwversion)/api/plan-guru-split-dft-r2c.c'
    , 'fftw-<(fftwversion)/api/plan-guru-split-dft.c'
    , 'fftw-<(fftwversion)/api/plan-many-dft-c2r.c'	
    , 'fftw-<(fftwversion)/api/plan-many-dft-r2c.c'
    , 'fftw-<(fftwversion)/api/plan-many-dft.c'
    , 'fftw-<(fftwversion)/api/plan-many-r2r.c'
    , 'fftw-<(fftwversion)/api/plan-r2r-1d.c'	
    , 'fftw-<(fftwversion)/api/plan-r2r-2d.c'
    , 'fftw-<(fftwversion)/api/plan-r2r-3d.c'
    , 'fftw-<(fftwversion)/api/plan-r2r.c'
    , 'fftw-<(fftwversion)/api/print-plan.c'
    , 'fftw-<(fftwversion)/api/rdft2-pad.c'		
    , 'fftw-<(fftwversion)/api/the-planner.c'
    , 'fftw-<(fftwversion)/api/version.c'
    , 'fftw-<(fftwversion)/api/api.h'
    , 'fftw-<(fftwversion)/api/f77funcs.h'
    , 'fftw-<(fftwversion)/api/fftw3.h'
    , 'fftw-<(fftwversion)/api/x77.h'
    , 'fftw-<(fftwversion)/api/guru.h'		
    , 'fftw-<(fftwversion)/api/guru64.h'
    , 'fftw-<(fftwversion)/api/mktensor-iodims.h'
    , 'fftw-<(fftwversion)/api/plan-guru-dft-c2r.h'
    , 'fftw-<(fftwversion)/api/plan-guru-dft-r2c.h'	
    , 'fftw-<(fftwversion)/api/plan-guru-dft.h'
    , 'fftw-<(fftwversion)/api/plan-guru-r2r.h'
    , 'fftw-<(fftwversion)/api/plan-guru-split-dft-c2r.h'		
    , 'fftw-<(fftwversion)/api/plan-guru-split-dft-r2c.h'
    , 'fftw-<(fftwversion)/api/plan-guru-split-dft.h'
    , 'fftw-<(fftwversion)/api/plan-guru64-dft-c2r.c'	
    , 'fftw-<(fftwversion)/api/plan-guru64-dft-r2c.c'
    , 'fftw-<(fftwversion)/api/plan-guru64-dft.c'
    , 'fftw-<(fftwversion)/api/plan-guru64-r2r.c'		
    , 'fftw-<(fftwversion)/api/plan-guru64-split-dft-c2r.c'
    , 'fftw-<(fftwversion)/api/plan-guru64-split-dft-r2c.c'			
    , 'fftw-<(fftwversion)/api/plan-guru64-split-dft.c'
    , 'fftw-<(fftwversion)/api/mktensor-iodims64.c'
    ]
}]}
