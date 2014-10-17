{'targets': [{
    'target_name': 'fftw3'
  , 'type': 'static_library'
  , 'sources': [
      'fftw3/api/fftw3.h'
    , 'fftw3/kernel/align.c'
    , 'fftw3/kernel/alloc.c'
    , 'fftw3/kernel/assert.c'
    , 'fftw3/kernel/awake.c'
    , 'fftw3/kernel/buffered.c'	
    , 'fftw3/kernel/cpy1d.c'
    , 'fftw3/kernel/cpy2d-pair.c'
    , 'fftw3/kernel/cpy2d.c'
    , 'fftw3/kernel/ct.c'
    , 'fftw3/kernel/debug.c'
    , 'fftw3/kernel/extract-reim.c'
    , 'fftw3/kernel/hash.c'
    , 'fftw3/kernel/iabs.c'	
    , 'fftw3/kernel/kalloc.c'
    , 'fftw3/kernel/md5-1.c'
    , 'fftw3/kernel/md5.c'
    , 'fftw3/kernel/minmax.c'
    , 'fftw3/kernel/ops.c'
    , 'fftw3/kernel/pickdim.c'
    , 'fftw3/kernel/plan.c'
    , 'fftw3/kernel/planner.c'	
    , 'fftw3/kernel/primes.c'
    , 'fftw3/kernel/print.c'
    , 'fftw3/kernel/problem.c'
    , 'fftw3/kernel/rader.c'
    , 'fftw3/kernel/scan.c'
    , 'fftw3/kernel/solver.c'
    , 'fftw3/kernel/solvtab.c'
    , 'fftw3/kernel/stride.c'	
    , 'fftw3/kernel/tensor.c'
    , 'fftw3/kernel/tensor1.c'
    , 'fftw3/kernel/tensor2.c'
    , 'fftw3/kernel/tensor3.c'
    , 'fftw3/kernel/tensor4.c'
    , 'fftw3/kernel/tensor5.c'
    , 'fftw3/kernel/tensor7.c'	
    , 'fftw3/kernel/tensor8.c'
    , 'fftw3/kernel/tensor9.c'
    , 'fftw3/kernel/tile2d.c'
    , 'fftw3/kernel/timer.c'
    , 'fftw3/kernel/transpose.c'
    , 'fftw3/kernel/trig.c'
    , 'fftw3/kernel/twiddle.c'	
    , 'fftw3/kernel/cycle.h'
    , 'fftw3/kernel/ifftw.h'
    , 'fftw3/api/apiplan.c'
    , 'fftw3/api/configure.c'
    , 'fftw3/api/execute-dft-c2r.c'		
    , 'fftw3/api/execute-dft-r2c.c'
    , 'fftw3/api/execute-dft.c'
    , 'fftw3/api/execute-r2r.c'
    , 'fftw3/api/execute-split-dft-c2r.c'	
    , 'fftw3/api/execute-split-dft-r2c.c'
    , 'fftw3/api/execute-split-dft.c'
    , 'fftw3/api/execute.c'			
    , 'fftw3/api/export-wisdom-to-file.c'
    , 'fftw3/api/export-wisdom-to-string.c'
    , 'fftw3/api/export-wisdom.c'	
    , 'fftw3/api/f77api.c'
    , 'fftw3/api/flops.c'
    , 'fftw3/api/forget-wisdom.c'
    , 'fftw3/api/import-system-wisdom.c'			
    , 'fftw3/api/import-wisdom-from-file.c'
    , 'fftw3/api/import-wisdom-from-string.c'
    , 'fftw3/api/import-wisdom.c'	
    , 'fftw3/api/malloc.c'
    , 'fftw3/api/map-r2r-kind.c'
    , 'fftw3/api/mapflags.c'
    , 'fftw3/api/mkprinter-file.c'
    , 'fftw3/api/mkprinter-str.c'	
    , 'fftw3/api/mktensor-iodims.c'
    , 'fftw3/api/mktensor-rowmajor.c'
    , 'fftw3/api/plan-dft-1d.c'
    , 'fftw3/api/plan-dft-2d.c'	
    , 'fftw3/api/plan-dft-3d.c'
    , 'fftw3/api/plan-dft-c2r-1d.c'
    , 'fftw3/api/plan-dft-c2r-2d.c'
    , 'fftw3/api/plan-dft-c2r-3d.c'	
    , 'fftw3/api/plan-dft-c2r.c'
    , 'fftw3/api/plan-dft-r2c-1d.c'
    , 'fftw3/api/plan-dft-r2c-2d.c'
    , 'fftw3/api/plan-dft-r2c-3d.c'	
    , 'fftw3/api/plan-dft-r2c.c'
    , 'fftw3/api/plan-dft.c'
    , 'fftw3/api/plan-guru-dft-c2r.c'
    , 'fftw3/api/plan-guru-dft-r2c.c'	
    , 'fftw3/api/plan-guru-dft.c'
    , 'fftw3/api/plan-guru-r2r.c'
    , 'fftw3/api/plan-guru-split-dft-c2r.c'		
    , 'fftw3/api/plan-guru-split-dft-r2c.c'
    , 'fftw3/api/plan-guru-split-dft.c'
    , 'fftw3/api/plan-many-dft-c2r.c'	
    , 'fftw3/api/plan-many-dft-r2c.c'
    , 'fftw3/api/plan-many-dft.c'
    , 'fftw3/api/plan-many-r2r.c'
    , 'fftw3/api/plan-r2r-1d.c'	
    , 'fftw3/api/plan-r2r-2d.c'
    , 'fftw3/api/plan-r2r-3d.c'
    , 'fftw3/api/plan-r2r.c'
    , 'fftw3/api/print-plan.c'
    , 'fftw3/api/rdft2-pad.c'		
    , 'fftw3/api/the-planner.c'
    , 'fftw3/api/version.c'
    , 'fftw3/api/api.h'
    , 'fftw3/api/f77funcs.h'
    , 'fftw3/api/fftw3.h'
    , 'fftw3/api/x77.h'
    , 'fftw3/api/guru.h'		
    , 'fftw3/api/guru64.h'
    , 'fftw3/api/mktensor-iodims.h'
    , 'fftw3/api/plan-guru-dft-c2r.h'
    , 'fftw3/api/plan-guru-dft-r2c.h'	
    , 'fftw3/api/plan-guru-dft.h'
    , 'fftw3/api/plan-guru-r2r.h'
    , 'fftw3/api/plan-guru-split-dft-c2r.h'		
    , 'fftw3/api/plan-guru-split-dft-r2c.h'
    , 'fftw3/api/plan-guru-split-dft.h'
    , 'fftw3/api/plan-guru64-dft-c2r.c'	
    , 'fftw3/api/plan-guru64-dft-r2c.c'
    , 'fftw3/api/plan-guru64-dft.c'
    , 'fftw3/api/plan-guru64-r2r.c'		
    , 'fftw3/api/plan-guru64-split-dft-c2r.c'
    , 'fftw3/api/plan-guru64-split-dft-r2c.c'			
    , 'fftw3/api/plan-guru64-split-dft.c'
    , 'fftw3/api/mktensor-iodims64.c'
    ]
}]}
