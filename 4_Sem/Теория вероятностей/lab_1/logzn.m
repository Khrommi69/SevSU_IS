function y = logzn(min, max, a)
for i = 1:1:5
    for j = 1:1:1000
        if ((min <= a(i,j)) && (max > a(i,j)))
            y(i,j) = 1;
        else 
            y(i,j) = 0;
        end
    end
end