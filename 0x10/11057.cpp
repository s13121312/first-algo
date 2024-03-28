#include <bits/stdc++.h>
using namespace std;

int b[1005][11]; // 길이가 n이고 j로끝나는수

int main(void)
{

    int n;
    cin >> n;

    for (int i = 0; i <= 9; i++)
    {
        b[1][i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                b[i][j] +=b[i-1][k];
                b[i][j]=b[i][j]%10007;
            }
        }
    }
    int sum=0;
    for(int i=0;i<=9;i++){
        sum+=b[n][i];
        sum%=10007;
    }
    cout << sum;
    return 0;
}