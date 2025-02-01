#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K, S[2][7]={},ans=0;
    cin >> N >> K;
    while(N--)
    {
        int r,t;
        cin >> r >> t;
        S[r][t]++;
    }
    for(int i=0;i<2;i++)
    {
        for(int j=1;j<7;j++)
        {
            if(S[i][j]>0)
            {
                ans+=S[i][j]/K;
                if(S[i][j]%K != 0)
                    ans++;
            }
        }
    }
    cout << ans;
    return 0;
}