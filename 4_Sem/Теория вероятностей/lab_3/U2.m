function [U2] = U2(N, M1, randValue)
    x = 0;
    for n = 1:1:N
        x = x + (randValue(n) - M1)^2;
    end
    U2 = (1/N) * x;
end