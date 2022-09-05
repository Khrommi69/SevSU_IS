function y = numbersTo01(min, max, a)
for i = 1:1000
    if ((min <= a(i)) && (max >= a(i)))
        y(i) = 1;
    else 
        y(i) = 0;
    end
end