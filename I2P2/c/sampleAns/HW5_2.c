#include <stdio.h>
#include <string.h>
// *Reviewed
int main()
{
    int n, occur[26] = {0};
    char str[101];
    scanf("%d", &n);
    scanf("%27s", str);
    while (getchar() != '\n');
    int length = strlen(str);
    for (int i = 0; i < length; i++)
        occur[str[i] - 'a'] += 1;
    for (int i = 0; i < 26; i++)
    {
        if (occur[i] > 1)//if a same alphabet occur more than one
        {
            printf("I'm the god of Knuckles!\n");
            return 0;
        }
    }
    if (n == 1)
        printf("I'm the god of Knuckles!\n");
    else
        printf("Different makes perfect\n");
    return 0;
}