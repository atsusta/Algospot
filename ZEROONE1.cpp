#include <stdio.h>
#include <string.h>

char buffer[1000001];
int start = 0, end = 0;

bool isZeroOne(int i, int j);

int main()
{
    int n;
    scanf("%s\n", buffer);
    scanf("%d", &n);
    while (n--)
    {
        int i, j;
        scanf("%d %d", &i, &j);
        if (isZeroOne(i, j))
            printf("%s\n", "Yes");
        else
            printf("%s\n", "No");

        memset(buffer, '0', sizeof(buffer));
        start = end = 0;
    }
}

bool isZeroOne(int i, int j)
{
    if (i > j)
    {
        int temp = i;
        i = j;
        j = temp;
    }

    int midResult = buffer[i];
    for (int k = i + 1; k <= j; k++)
    {
        printf("%c", buffer[k]);
        midResult = midResult ^ buffer[k];
        if (midResult == 1) return false;
    }
    return true;
}
