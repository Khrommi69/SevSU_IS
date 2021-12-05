#include <stdio.h>

typedef struct timeStruct{
    int h;
    int m;
    int s;
} timeStruct;

timeStruct inc(timeStruct a);

int main()
{
    timeStruct a;

        printf("input time (h,m,s):\n");
        scanf("%d", &a.h);
        scanf("%d", &a.m);
        scanf("%d", &a.s);

        printf("Default time: \"%d : %d : %d\"\n", a.h, a.m, a.s);
        a = inc(a);
        printf("Changed time: \"%d : %d : %d\"\n", a.h, a.m, a.s);

    return 0;
}


timeStruct inc(timeStruct a)
{
    if (a.s != 59)
    {
        a.s += 1;
        return a;
    }

    a.s = 0;
    if (a.m != 59)
    {
        a.m += 1;
        return a;
    }

    a.m = 0;
    a.h += 1;
    return a;
}