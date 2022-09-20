% Лабораторная работа №4
N = 30;
M = 5;
table = [8,7,8,12,13,10,12,18,21,7,8,9,15,16,17,8,7,13,12,15,19,21,20,13,18,8,9,13,12,27;240,200,280,430,500,400,400,640,720,250,250,350,620,600,640,290,240,550,470,660,720,780,720,540,660,270,350,480,470,800];

table=rangeX(table);

xmin = table(1,1);
xmax = table(1,N);

Lx = (xmax - xmin) / M;

[r1] = cut(table, xmin - 1, xmin + Lx);
[r2] = cut(table, xmin + Lx, xmin + 2 * Lx);
[r3] = cut(table, xmin + 2 * Lx, xmin + 3 * Lx);
[r4] = cut(table, xmin + 3 * Lx, xmin + 4 * Lx);
[r5] = cut(table, xmin + 4 * Lx, xmin + 5 * Lx);

[mr1] = mid(r1);
[mr2] = mid(r2);
[mr3] = mid(r3);
[mr4] = mid(r4);
[mr5] = mid(r5);

pg1 = mr1(2)/mr1(1)/10;
pg2 = mr2(2)/mr2(1)/10;
pg3 = mr3(2)/mr3(1)/10;
pg4 = mr4(2)/mr4(1)/10;
pg5 = mr5(2)/mr5(1)/10;

pg = [pg1, pg2, pg3, pg4, pg5];

% вывод данных
disp(sprintf('Интервалы по X = %d .. %d; xj = %.2f; yj = %.2f; ШП = %.2f; fj = %d', xmin, xmin + 1*Lx, mr1(1), mr1(2), pg1, length(r1)));
disp(sprintf('Интервалы по X = %d .. %d; xj = %.2f; yj = %.2f; ШП = %.2f; fj = %d', xmin + 1*Lx, xmin + 2*Lx, mr2(1), mr2(2), pg2, length(r2)));
disp(sprintf('Интервалы по X = %d .. %d; xj = %.2f; yj = %.2f; ШП = %.2f; fj = %d', xmin + 2*Lx, xmin + 3*Lx, mr3(1), mr3(2), pg3, length(r3)));
disp(sprintf('Интервалы по X = %d .. %d; xj = %.2f; yj = %.2f; ШП = %.2f; fj = %d', xmin + 3*Lx, xmin + 4*Lx, mr4(1), mr4(2), pg4, length(r4)));
disp(sprintf('Интервалы по X = %d .. %d; xj = %.2f; yj = %.2f; ШП = %.2f; fj = %d', xmin + 4*Lx, xmin + 5*Lx, mr5(1), mr5(2), pg5, length(r5(1))));

pg = pg1 + pg2 + pg3 + pg4 + pg5;
pg = pg / 5;

%3 пункт
x1 = (mr1(1) * length(r1) + mr2(1) * length(r2) + mr3(1) * length(r3) + mr4(1) * length(r4) + mr5(1) * length(r5(1)) ) / N;
y1 = (mr1(2) * length(r1) + mr2(2) * length(r2) + mr3(2) * length(r3) + mr4(2) * length(r4) + mr5(2) * length(r5(1)) ) / N;

Sxy = (mr1(1) - x1) * (mr1(2) - y1) * length(r1) + ...
(mr2(1) - x1) * (mr2(2) - y1) * length(r2) + ...
(mr3(1) - x1) * (mr3(2) - y1) * length(r3) + ...
(mr4(1) - x1) * (mr4(2) - y1) * length(r4) + ...
(mr1(1) - x1) * (mr5(2) - y1) * length(r5);
Sxy = Sxy / N;

Dx = (mr1(1) - x1)^2 * length(r1) + ...
(mr2(1) - x1)^2 * length(r2) + ...
(mr3(1) - x1)^2 * length(r3) + ...
(mr4(1) - x1)^2 * length(r4) + ...
(mr5(1) - x1)^2 * length(r5);
Dx = Dx / N;

Dy = (mr1(2) - x1)^2 * length(r1) + ...
(mr2(2) - x1)^2 * length(r2) + ...
(mr3(2) - x1)^2 * length(r3) + ...
(mr4(2) - x1)^2 * length(r4) + ...
(mr5(2) - x1)^2 * length(r5);
Dy = Dy / N;

a1 = Sxy / Dx;
a0 = y1-a1*x1;

x = [r1(1),r2(1),r3(1),r4(1),r5(1)];
plot(a0+a1*x, 'c-O');

xlabel('млн. руб')
ylabel('тыс. руб')

n = 1000;
tp = 2;

ax1 = x1-tp * sqrt(Dx)/sqrt(N) * sqrt((n - N)/(n - 1));
ax2 = x1+tp * sqrt(Dx)/sqrt(N) * sqrt((n - N)/(n - 1));

ay1 = y1-tp * sqrt(Dy)/sqrt(N) * sqrt((n - N)/(n - 1));
ay2 = y1+tp * sqrt(Dy)/sqrt(N) * sqrt((n - N)/(n - 1));

apg1 = abs(pg-tp * sqrt(Sxy)/sqrt(N) * sqrt((n - N)/(n - 1)));
apg2 = pg+tp * sqrt(Sxy)/sqrt(N) * sqrt((n - N)/(n - 1));

disp(sprintf('%.3f <= X <= %.3f', ax1, ax2));
disp(sprintf('%.3f <= Y <= %.3f', ay1, ay2));
disp(sprintf('%.3f <= ШП <= %.3f', apg1, apg2));

pg