function [U4] = U4(N, M1, randValue)
    x = 0;
    for n = 1:1:N
        x = x + (randValue(n) - M1)^4;
    end
    U4 = (1/N) * x;
end