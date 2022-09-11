function [M1] = M1(N, randValue)
    x = 0;
    for n = 1:1:N
        x = x + randValue(n);
    end
    M1 = (1/N) * x;
end