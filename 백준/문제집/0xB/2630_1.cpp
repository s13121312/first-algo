#include <bits/stdc++.h>
using namespace std;

int arr[130][130];
int n;

bool check(int n, int x, int y)
{
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (arr[x][y] != arr[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int b_cnt = 0;
int w_cnt = 0;

void func(int n, int x, int y)
{
    // 4등분해서 나눈 부분이  다 같으면
    // 색종이개수로 증가

    if (check(n, x, y))
    {
        // 색깔 판별해야함
        if (arr[x][y] == 1)
        {
            b_cnt++;
            return;
        }
        else
        {
            w_cnt++;
            return;
        }
    }
    else{
        func(n / 2, x, y);                 // 1사분면
        func(n / 2, x, y + n / 2);         // 2사분면
        func(n / 2, x + n / 2, y);         // 3사분면
        func(n / 2, x + n / 2, y + n / 2); // 4사분면
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
    cout << w_cnt << '\n'
         << b_cnt;
    return 0;
}