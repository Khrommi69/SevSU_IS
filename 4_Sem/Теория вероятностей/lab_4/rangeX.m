%Функция сортировки по агрументу X
function [res] = rangeX(table)
    for i=1:1:30
        for j=i:1:30
            if (j > 30)
                continue
            end
            if table(1,i) > table(1,j)
                xi = table(1,i);
                yi = table(2,i);
                table(1,i) = table(1,j);
                table(2,i) = table(2,j);
                table(1,j) = xi;
                table(2,j) = yi;
            end
        end
    end
    res = table;
end