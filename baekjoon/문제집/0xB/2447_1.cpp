#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2200; // Adjust the maximum size as needed

string star[MAX_N];

void func(int n, int x, int y)
{
    // base
    if (n == 3)
    {
        for (int i = x; i < x + 3; i++)
        {
            for (int j = y; j < y + 3; j++)
            {
                if (i == x + 1 && j == y + 1)
                {
                    star[i][j] = ' ';
                }
                else
                {
                    star[i][j] = '*';
                }
            }
        }
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(i==1 && j==1) continue;
            func(n / 3, x + i * n / 3, y + j * n / 3);
        }
    }
}

int main(void)
{
    int n;
    cin >> n;

    //string 대신 char 로 star선언하면 fill을 쓸수있음
    // Initialize the star array
    for (int i = 0; i < n; i++)
    {
        star[i] = string(n, ' '); // Initialize with spaces
    }

    func(n, 0, 0);

    // Print the pattern
    for (int i = 0; i < n; i++)
    {
        cout << star[i] << '\n';
    }

    return 0;
}
