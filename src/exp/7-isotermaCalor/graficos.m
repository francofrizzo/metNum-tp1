addpath ../../tools

horno('isotermaCalor-50.in', 'isotermaCalor-50.sol', 'isotermaCalor-50-iso2.sol', 'graficos/isotermaCalor-50', 'graficos/isotermaCalor-50-iso');
horno('isotermaCalor-200.in', 'isotermaCalor-200.sol', 'isotermaCalor-200-iso2.sol', 'graficos/isotermaCalor-200', 'graficos/isotermaCalor-200-iso');

hornoVsPosta('isotermaCalor-200.in', 'isotermaCalor-200.sol', 'isotermaCalor-200-iso2.sol', 'graficos/isotermaCalor-200', 'graficos/isotermaCalor-iso', 'isotermaCalor-50.in', 'isotermaCalor-50.sol', 'isotermaCalor-50-iso2.sol');
