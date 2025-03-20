#include <bits/stdc++.h>
using namespace std;

int paper[130][130];
int n;
// n은 2, 4, 8, 16, 32, 64, 128 중 하나

int ans[2];
bool check(int n, int x, int y) // n이 한변인데 한변이 절반으로 되서 4개의 사각형으로 나눠지면 같은색으로 채워져있지않으면 계속 반복
{
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (paper[i][j] != paper[x][y])
            {
                return false;
            }
        }
    }
    return true;
}

void func(int n, int x, int y)
{
    if(check(n,x,y))
    {
        ans[paper[x][y]]++;
        return;
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            func(n/2, x+i*n/2, y+j*n/2);
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
            cin >> paper[i][j];
        }
    }

    func(n, 0, 0);
}
