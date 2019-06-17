[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 10
  ny = 10
[]

[Variables]
  [./u]
  [../]
[]

[Kernels]
  [./ly]
    type = LaplaceYoung
    variable = u
    # kappa = 
  [../]
[]

[BCs]
  [./all]
    type = NeumannBC
    variable = u
    boundary = 'left right top bottom'
    value = 0.2
  [../]
[]

[Executioner]
  type = Steady
  solve_type = 'NEWTON'
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
