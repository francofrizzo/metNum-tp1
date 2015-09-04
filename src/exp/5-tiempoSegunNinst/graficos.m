% Tiempo de ejecución (segundos) en función del número de instancias

% Caso A
% m + 1 = 25, n = 40
% (EG, LU)
h = figure();

x = 1:6;
y = [3.099746 3.088397; 6.204906 3.089928; 9.333475 3.107586; 12.392685 3.109775; 15.497981 3.119630; 18.562135 3.123978];
bar(y);
legend ('Eliminacion Gaussiana', 'Factorizacion LU', 'location', 'northwest');
xlabel("ninst");
ylabel("Tiempo de ejecucion");
print('5a','-dpng');
