#include "LaplaceYoung.h"

registerADMooseObject("FrogApp", LaplaceYoung);

defineADValidParams(
    LaplaceYoung,
    ADKernel,
    params.addClassDescription("The Laplace Young terms.");
    params.addParam<Real>("kappa", 1, "The Kappa coefficient.");
  );

template <ComputeStage compute_stage>
LaplaceYoung<compute_stage>::LaplaceYoung(const InputParameters & parameters)
: ADKernel<compute_stage>(parameters),
  _kappa(adGetParam<Real>("kappa"))
{
}

template <ComputeStage compute_stage>
ADReal
LaplaceYoung<compute_stage>::computeQpResidual()
{
  ADReal k = 1. / std::sqrt(1 + _grad_u[_qp] * _grad_u[_qp]);
  return _grad_test[_i][_qp] * k * _grad_u[_qp] + _test[_i][_qp] * _kappa * _u[_qp];
}

adBaseClass(LaplaceYoung);
