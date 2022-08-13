#include <iostream>

using namespace std;

int binary_search(int arr[], int left, int right, int element_found);

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int location_found = binary_search(arr, 0, n - 1, x);
    (location_found == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << location_found;
    return 0;
}

int binary_search(int arr[], int left, int right, int element_found)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == element_found)
            return mid;

        if (arr[mid] > element_found)
            return binary_search(arr, left, mid - 1, element_found);

        return binary_search(arr, mid + 1, right, element_found);
    }

    return -1;
}
