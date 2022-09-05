function y = chast(x)
count = 0;
for i = 1:1:1000
    if (x(i)==1)
        count = count +1;
    end
    y(i)=count/i;
end

