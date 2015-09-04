addpath ../../tools

horno('4-5.in', '4-5.sol', '4-5-iso2.sol', 'graficos/4-5', 'graficos/4-5-iso');
horno('4-10.in', '4-10.sol', '4-10-iso2.sol', 'graficos/4-10', 'graficos/4-10-iso');
horno('4-20.in', '4-20.sol', '4-20-iso2.sol', 'graficos/4-20', 'graficos/4-20-iso');
horno('4-40.in', '4-40.sol', '4-40-iso2.sol', 'graficos/4-40', 'graficos/4-40-iso');
horno('4-60.in', '4-60.sol', '4-60-iso2.sol', 'graficos/4-60', 'graficos/4-60-iso');
horno('4-80.in', '4-80.sol', '4-80-iso2.sol', 'graficos/4-80', 'graficos/4-80-iso');

x = [5, 10, 20, 40, 60, 80, 90]; % Radio interno
y = [0.44124, 0.557452, 0.683942, 0.822686, 0.90908, 0.973116, 1]
plot(x, y);
hold on;
plot(x, y, '.');
hold off;
print('4','-dpng');
