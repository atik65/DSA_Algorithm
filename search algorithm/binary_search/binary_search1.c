// [10,12,15,17,21,25,26,30]

#include <stdio.h>

int binary_search(int arr[], int n, int x)
{

    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }

        if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}
// time complexity = O(log n)

int main()
{
    int arr[] = {10, 12, 15};

    int index = binary_search(arr, 3, 12);
    printf("%d", index);

    return 0;
}
