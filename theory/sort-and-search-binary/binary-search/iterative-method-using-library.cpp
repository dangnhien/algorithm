#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> arr, int to_find);

int main()
{
    vector<int> arr = {1, 3, 4, 5, 6};
    int to_find = 1;
    binary_search(arr, to_find);

    to_find = 6;
    binary_search(arr, to_find);

    to_find = 10;
    binary_search(arr, to_find);

    return 0;
}

int binary_search(vector<int> arr, int to_find)
{
    int low = 0, hight = arr.size() - 1;
    int mid;

    while (hight - low > 1)
    {
        mid = low + (hight - low) / 2;
        if (arr[mid] < to_find)
            low = mid + 1;
        else
            hight = mid;
    }

    if (arr[low] == to_find)
        cout << "Found "
             << "At Index " << low << endl;
    else if (arr[hight] == to_find)
        cout << "Found "
             << "At Index " << hight << endl;
    else
        cout << "Not Found" << endl;
}