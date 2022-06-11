#include <stdio.h>

void bubble_sort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n; i++)
    {

        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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

    bubble_sort(test_arr, 7);

    printf("Printing sorted array\n \n");

    for (i = 0; i < 7; i++)
    {
        printf("%d \n", test_arr[i]);
    }

    return 0;
}