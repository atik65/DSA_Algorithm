#include <stdio.h>

void selection_sort(int arr[], int n)
{
    int i, j, temp, min_index;

    for (i = 0; i < n - 1; i++)
    {
        min_index = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        if (i != min_index)
        {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

int main()
{
    int test_arr[100] = {5, 1, 25, -2, -56, 36, 25}, i;

    for (i = 0; i < 7; i++)
    {
        printf("%d \n", test_arr[i]);
    }

    selection_sort(test_arr, 7);

    printf("Printing sorted array\n \n");

    for (i = 0; i < 7; i++)
    {
        printf("%d \n", test_arr[i]);
    }

    return 0;
}