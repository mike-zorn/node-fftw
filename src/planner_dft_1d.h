#ifndef PLANNER_DFT_1D
#define PLANNER_DFT_1D

#include <nan.h>
#include <fftw3.h>

class PlannerDft1d : public NanAsyncWorker {
  public:
    void HandleOKCallback();
    PlannerDft1d(NanCallback *callback, int size, int sign, unsigned flags);
    ~PlannerDft1d();  
    void Execute();

  private:
    int size;
    int sign;
    unsigned flags;
    fftw_plan plan;
    fftw_complex* in;
    fftw_complex* out;
};

#endif
