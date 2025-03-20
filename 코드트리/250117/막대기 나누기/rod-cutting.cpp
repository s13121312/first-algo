#include <bits/stdc++.h>
using namespace std;

int n;
int len[105];
int val[105];
int dp[105][105];
int ans = 0;

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> val[i];
        len[i] = i+1;
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         dp[i][j] = INT_MIN;
    //     }
    // }
    // dp[0][0] = 0;
    // for(int i=1;i<=n;i++){
    //     if(i >= len[0]){
    //         dp[0][i] = val[0]; 
    //     } else{
    //         dp[0][i] = 0;
    //     }
    // }
    
}

void print(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

/*void pro(){


    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++){
            if(j >= len[i]){
                dp[i][j] = max(dp[i][j], dp[i][j-len[i]] + val[i]);
            } else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    for(int i=0;i<=n;i++){
        ans = max(ans, dp[n-1][i]);
    }
    //print();

    cout << ans;
}*/

int dp1[105];

void pro2(){

    dp1[0] = 0;
    for(int i=1;i<=n;i++){
        dp1[i] = INT_MIN;
    }

    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++){
            if(j-len[i] >= 0)dp1[j] = max(dp1[j], dp1[j-len[i]] + val[i]); 
            
        }
    }

    for(int i=1;i<=n;i++){
        ans = max(ans, dp1[i]);
    }
    cout << ans;
}

int main() {
    // Please write your code here.
    input();
    //pro();
    pro2();

    return 0;
}