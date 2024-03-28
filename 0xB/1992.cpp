#include <bits/stdc++.h>
using namespace std;

string vid[65];

bool check(int n, int x, int y)
{
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (vid[x][y] != vid[i][j])
                return false;
        }
    }
    return true;
}

string tmp = "";
void func(int n, int x, int y)
{

    if (check(n, x, y))
    {

        char c = vid[x][y];
        tmp += c;
    }
    else
    {
        tmp += '(';
        func(n / 2, x, y);

        func(n / 2, x, y + n/2);

        func(n / 2, x + n/2, y);

        func(n / 2, x + n/2, y + n/2);
        tmp += ')';
    }
}

int main(void)
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vid[i][j];
        }
    }

    
    func(n, 0, 0);
    cout << tmp;

    return 0;
}