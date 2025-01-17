#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[105][2];
int dp[105][10005];

void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = INT_MIN;
        }
    }

    dp[0][0] = 0;

    for(int i=1;i<=m;i++){
        dp[0][i] = (i/arr[0][0])*arr[0][1];
    }

}

void pro(){

    for(int j=0;j<=m;j++){
        for(int i=1;i<n;i++){
            if(j >= arr[i][0]){
                dp[i][j] = max(dp[i-1][j], dp[i][j-arr[i][0]] + arr[i][1]);
            } 
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    cout << dp[n-1][m];

}

int main() {
    // Please write your code here.
    input();
    pro();

    return 0;
}