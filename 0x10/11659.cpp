#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int sum[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    sum[0]=0;
    // arr에 5,4,3,2,1 들어가있다
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum[i]=sum[i-1]+arr[i];
    }
    

    while(m--)
    {
        int i, j;
        cin >> i >> j;
        cout << sum[j] - sum[i - 1] <<'\n';
    }


    return 0;
}
