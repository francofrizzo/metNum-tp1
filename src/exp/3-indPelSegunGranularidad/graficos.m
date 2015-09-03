addpath ../../tools

horno('3-5.in', '3-5.sol', '3-5-iso2.sol', 'graficos/3-5', 'graficos/3-5-iso');
horno('3-10.in', '3-10.sol', '3-10-iso2.sol', 'graficos/3-10', 'graficos/3-10-iso');
horno('3-20.in', '3-20.sol', '3-20-iso2.sol', 'graficos/3-20', 'graficos/3-20-iso');
horno('3-40.in', '3-40.sol', '3-40-iso2.sol', 'graficos/3-40', 'graficos/3-40-iso');
horno('3-80.in', '3-80.sol', '3-80-iso2.sol', 'graficos/3-80', 'graficos/3-80-iso');

x = [5*10, 10*15, 20*20, 40*25, 80*30]; % Cant. ángulos
y = [0.633849, 0.633849, 0.635172, 0.636719, 0.637951];
plot(x, y);
hold on;
plot(x, y, '.');
hold off;
print('3','-dpng');
