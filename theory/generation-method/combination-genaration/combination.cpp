/*
    sinh tổ hợp chập k của n phần tử
*/

#include <iostream>

using namespace std;

int a[50], n, k;

void input()
{
    cout << "\nInput n, k: ";
    cin >> n >> k;
}

// sinh tổ hợp kế tiếp
void generation(int &ok)
{
    int i = k;
    while (i > 0 && a[i] == n + i - k)
        i--;
    a[i]++;
    if (i > 0)
    {
        for (int j = i + 1; j <= n; j++)
            a[j] = a[i] + j - i;
    }
    else
        ok = 0; //   đã tìm dược tổ hợp cuối cùng
}

// xuất tổ hợp hiện tại
void output()
{
    for (int i = 1; i <= k; i++)
        cout << a[i] << " ";

    cout << endl;
}

void next(int ok)
{
    for (int i = 1; i <= n; i++)
        a[i] = i;
    while (ok) // ok==1
    {
        output();
        generation(ok);
    }
}

int main()
{
    int ok_1 = 1;
    input();
    next(ok_1);

    return 0;
}