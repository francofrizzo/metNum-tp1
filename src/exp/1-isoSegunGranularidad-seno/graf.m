addpath '../../tools'

figure;
hold on;

hornoApilar('exp6a-10.in', 'exp6a-10.sol', 'exp6a-10-iso2.sol', 'r');

hornoApilar('exp6a-30.in', 'exp6a-30.sol', 'exp6a-30-iso2.sol', 'b');

hornoApilar('exp6a-50.in', 'exp6a-50.sol', 'exp6a-50-iso2.sol', 'm');

hornoApilar('exp6a-70.in', 'exp6a-70.sol', 'exp6a-70-iso2.sol', 'g');

print('graficos/apiladosa', '-dpng')

% hornoApilar('exp6.in', 'exp6.sol', 'exp6-iso2.sol');
