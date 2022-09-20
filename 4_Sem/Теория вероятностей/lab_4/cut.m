%Функция, которая делит таблицу на интервалы
function [res] = cut(table, a, b)
    amp = 0;
    start = 0;
    for i=1:1:30
        if table(1, i) > a && table(1, i) <= b
            if start == 0
                start = i;
            end
            amp = amp + 1;
        end
    end
    res = table(1:2, start:start-1+amp);
end