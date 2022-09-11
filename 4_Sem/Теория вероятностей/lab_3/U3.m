function [U3] = U3(N, M1, randValue)
    x = 0;
    for n = 1:1:N
        x = x + (randValue(n) - M1)^3;
    end
    U3 = (1/N) * x;
end