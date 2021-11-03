#include <stdio.h>
#include <string.h>

int main()
{
    char str[50];
    int len;
    scanf("%s", str);
    len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= '0' && str[i] <= '9') //is num
        {
            printf("%c", str[i]);
            {
                if (str[i + 1] < '0' || str[i + 1] > '9') // if next is not num
                    printf("\n");
            }
        }
    }

    return (0);
}