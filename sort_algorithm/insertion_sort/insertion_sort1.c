#include <stdio.h>

void insertion_sort(int arr[], int n)
{
    int i, j, item;

    for (i = 1; i < n; i++)
    {
        item = arr[i];

        j = i - 1;

        while (j >= 0 && arr[j] > item)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = item;
    }
}

int main()
{

    int test_arr[100] = {4, 3, 2, 1}, i;

    for (i = 0; i < 4; i++)
    {
        printf("%d \n", test_arr[i]);
    }

    insertion_sort(test_arr, 4);

    printf("Printing sorted array\n \n");

    for (i = 0; i < 4; i++)
    {
        printf("%d \n", test_arr[i]);
    }

    return 0;
}