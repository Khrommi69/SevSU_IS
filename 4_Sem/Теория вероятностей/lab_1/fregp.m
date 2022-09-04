function y = fregp(v, m)
count = 0;
for i = 1:1:m
    if (v(1,i) == 1)
        count = count + 1;
    end
    y(i) = count/m;
end
