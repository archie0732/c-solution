#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// qsort 條件式
int compareStrings(const void *a, const void *b)
{
    char ab[20], ba[20];
    sprintf(ab, "%s%s", (char *)a, (char *)b);
    sprintf(ba, "%s%s", (char *)b, (char *)a);
    return strcmp(ba, ab);
}

int main()
{
    char input[1000];

    while (fgets(input, sizeof(input), stdin) != NULL)
    {
        if (strcmp(input, "0\n") == 0)
            break;

        // 將輸入分割成單獨的數字
        char *token = strtok(input, " \n");
        char numbers[100][20];
        int count = 0;

        while (token != NULL)
        {
            strcpy(numbers[count], token);
            token = strtok(NULL, " \n");
            count++;
        }

        qsort(numbers, count, sizeof(numbers[0]), compareStrings);

        for (int i = 0; i < count - 1; i++)
        {
            printf("%s", numbers[i]);
        }
        printf("\n");
    }

    return 0;
}