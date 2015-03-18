#include <stdio.h>
//o[m]zo[n]j[m*n](m>=0, n>=1)

int check(char *str)
{
        int i = -1;
        int a, b;

        while (str[++i] == 'o') ;
        if (str[i] == 'z') a = i;
        else return 0;

        while (str[++i] == 'o') ;
        if (str[i] == 'j') b = i-a-1;
        else return 0;

        while (str[++i] == 'o') ;
        if (str[i] == '\0')
                if (((i-a-b-2) == a*b) && b>0 )
                        return 1;
        return 0;
}

int main(int argc, char* argv[])
{
        char str[1001];

        while (~scanf("%s",str)) {
                if (check(str))
                {
                        puts("Accepted");
                } else {
                        puts("Wrong Answer");
                }
        }

        return 0;
}
