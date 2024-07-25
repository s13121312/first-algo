#include<bits/stdc++.h>
using namespace std;

int arr[1030][1030];
int dp[1030][1030];

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    dp[1][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
            if(j==1)dp[i][j] = dp[i-1][n] + arr[i][j];
            dp[i][j] = dp[i][j-1]+arr[i][j];
        }
    }

    for(int i=0;i<m;i++){
        int x1,x2,y1,y2;

        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        
        for(int i=x1;i<=x2;i++){
            ans += dp[i][y2]-dp[i][y1-1];
        }
        cout << ans<<'\n';
        
    }


    return 0;
}