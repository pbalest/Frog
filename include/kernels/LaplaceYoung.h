#pragma once

#include "ADKernel.h"

template <ComputeStage>
class LaplaceYoung;

declareADValidParams(LaplaceYoung);

template <ComputeStage compute_stage>
class LaplaceYoung : public ADKernel<compute_stage>
{
public:
  LaplaceYoung(const InputParameters & parameters);

protected:
  virtual ADReal computeQpResidual() override;
  const Real & _kappa;
  usingKernelMembers;
};
