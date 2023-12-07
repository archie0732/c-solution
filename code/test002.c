#include <stdio.h>

void reverseArray(int arr[], int size)
{
    int *start = arr;
    int *end = arr + size - 1;

    while (start < end)
    {

        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main()
{
    int size;

    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++)
    {

        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    reverseArray(arr, size);

    printf("\n反轉後的陣列: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
