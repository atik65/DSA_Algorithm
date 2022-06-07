// [1,2,3,4,5,6] find any number form this array

int linear_search(int arr[], int n, int x)
{

    int i;

    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }

    return -1;
}

// time complexity = O(n)
// space complexity = O(1)