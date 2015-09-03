% Tiempo de ejecución (segundos) en función del número de instancias

% Caso A
% m + 1 = 25, n = 40
% (EG, LU)
h = figure();

x = 1:6;
y = [3.088397 3.099746; 3.089928 6.204906; 3.107586 9.333475; 3.109775 12.392685; 3.119630 15.497981; 3.123978 18.562135];
bar(y);
print('5a','-dpng');
