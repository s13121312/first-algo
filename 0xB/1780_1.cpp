#include <bits/stdc++.h>
using namespace std;

int arr[2200][2200];
int n;

bool check(int n, int x, int y)
{

    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (arr[x][y] != arr[i][j])
                return false;
        }
    }
    return true;
}

int m = 0;
int zero = 0;
int p = 0;

void func(int n, int x, int y)
{

    if (check(n,x,y))
    {
        if (arr[x][y] == -1)
        {
            m++;
            return;
        }
        else if (arr[x][y] == 0)
        {
            zero++;
            return;
        }
        else
        {
            p++;
            return;
        }
    }

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            func(n / 3, x + i * n / 3, y + j * n / 3);
        }
    }
}

int main(void)
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    func(n, 0, 0);

    cout << m << '\n'
         << zero << '\n'
         << p;

    return 0;

}