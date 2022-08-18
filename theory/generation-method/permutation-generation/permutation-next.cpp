#include <iostream>
#include <iomanip>

using namespace std;

void create(int a[], int &n)
{
    cout << "\nInput n: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
        a[i] = i;
}

int generation(int a[], int n, int &ok)
{
    int i = n - 1;
    while (i > 0 && a[i] > a[i + 1])
        i--;
    if (i > 0)
    {
        int k = n;
        while (a[i] > a[k])
            k--;
        int t = a[i];
        a[i] = a[k];
        a[k] = t;

        int r = i + 1, s = n;
        while (r <= s)
        {
            int tg = a[r];
            a[r] = a[s];
            a[s] = tg;

            r++;
            s--;
        }
    }
    else
        ok = 0;
}

void output(int a[], int n)
{
    for (int i = 1; i <= n; i++)
        cout << setw(3) << a[i];
    cout << endl;
}

void next(int a[], int n, int ok)
{
    while (ok)
    {
        output(a, n);
        generation(a, n, ok);
    }
}

int main()
{
    int a[100];
    int n, ok = 1;
    create(a, n);
    next(a, n, ok);
    return 0;
}