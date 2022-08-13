#include <iostream>

using namespace std;

int binary_search(int arr[], int left, int right, int value);

int main()
{
    int arr[] = {2, 3, 4, 5, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binary_search(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}

int binary_search(int arr[], int left, int right, int value)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == value)
            return mid;

        if (arr[mid] < value)
            return left = mid + 1;

        else
            return right = mid - 1;
    }
    return -1;
}
