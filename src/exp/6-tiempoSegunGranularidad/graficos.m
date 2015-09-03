% Tiempos de ejecución según granularidad

% Caso A: Variando ángulos (m + 1 = 30)
% (EG, LU)

x = [10, 30, 50, 70, 90]; % Cant. ángulos
y = [0.09335425 0.09196125; 2.25882775 2.25695850; 10.40710775 10.40538050; 28.47581550 28.50210100; 60.43221975 60.50333525]
plot(x, y);
print('6a','-dpng');

% Caso B: Variando radios (n = 60)
% (EG, LU)

figure;
x = [10, 30, 50, 70]; % Cant. ángulos
y = [0.67524000 0.67400350; 17.94450675 17.98105550; 82.86414400 83.05790825; 227.07038100 227.68770850]
plot(x, y);
print('6b','-dpng');
