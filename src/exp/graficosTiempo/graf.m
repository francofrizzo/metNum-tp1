% EG vs LU, m + 1 = 25, n = 40
% Tiempo de ejecución (segundos) en función del número de instancias
h = figure();

x = 1:6;
y = [3.088397 3.099746; 3.089928 6.204906; 3.107586 9.333475; 3.109775 12.392685; 3.119630 15.497981; 3.123978 18.562135];
bar(y);
% print('egVsLu','-dpng');


% Tiempos de ejecución según granularidad

% Radios fijos (m + 1 = 30)
% Primero EG, luego LU

x = [10, 30, 50, 70, 90]; % Cant. ángulos
y = [0.09335425 0.09196125; 2.25882775 2.25695850; 10.40710775 10.40538050; 28.47581550 28.50210100; 60.43221975 60.50333525]
plot(x, y);
% print('tPorGran-radiosFijos','-dpng');

% Ángulos fijos (n = 60)
% Primero EG, luego LU

figure;
x = [10, 30, 50, 70]; % Cant. ángulos
y = [0.67524000 0.67400350; 17.94450675 17.98105550; 82.86414400 83.05790825; 227.07038100 227.68770850]
plot(x, y);
% print('tPorGran-angFijos','-dpng');
