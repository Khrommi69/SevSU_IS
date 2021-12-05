#include <stdio.h>

int main()
{
    int points = 0;
    int colons = 0;
    int semicolons = 0;
    int exclamation_marks = 0;
    int question_marks = 0;
    int commas = 0;
    char str[999999];
    fgets(str, 999998, stdin);

    unsigned long i;
    for(i=0; str[i] != '\0'; i++)
    {
        switch (str[i])
        {
            case '.' : ++points; break;
            case ':' : ++colons; break;
            case ';' : ++semicolons; break;
            case '!' : ++exclamation_marks; break;
            case '?' : ++question_marks; break;
            case ',' : ++commas; break;
        }
    }

    printf(". = %d\n", points);
    printf(": = %d\n", colons);
    printf("; = %d\n", semicolons);
    printf("! = %d\n", exclamation_marks);
    printf("? = %d\n", question_marks);
    printf(", = %d", commas);

    return 0;
}
