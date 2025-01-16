#include <bits/stdc++.h>
using namespace std;

int n, m;
int w[105];
int v[105];
int dp[105][10005];
int ans = 0;

void print(){
    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> w[i] >> v[i];
    }

    dp[0][0] = 0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            if(j >= w[i]){
                dp[i][j] = v[i];
            }
        }
    }

    //print();
}

void pro(){


    for(int i=1;i<n;i++){
        for(int j=m;j>=1;j--){
            if(j >= w[i]){
                //if(dp[i][j-w[i]] == 0)continue;
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }

    //print();
    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;

}

int main() {
    // Please write your code here.
    input();
    pro();

    return 0;
}