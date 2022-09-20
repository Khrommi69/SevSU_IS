% Нахождение среднего значения по Xi и Yi
function [res] = mid(table)
    Xi = 0;
    Yi = 0;
    l = length(table(1));
    for i=1:1:l
        Xi = Xi + table(1,i);
        Yi = Yi + table(2,i);
    end
    res = [Xi / l; Yi / l];
end
