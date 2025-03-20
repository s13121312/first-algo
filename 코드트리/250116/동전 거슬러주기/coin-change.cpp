#include <bits/stdc++.h>
using namespace std;

int n, m;
int coin[105];
int dp[10005];

void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> coin[i];
    }

    dp[0] = 0;
    for(int i=1;i<=m;i++){
        dp[i] = INT_MAX;
    }
}

void print(){
    for(int i=1;i<=m;i++){
        cout << dp[i] << ' ';
    }
    cout << '\n';

}

void pro(){


    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            if(i >= coin[j]){
                if(dp[i - coin[j]] == INT_MAX)continue;

                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }

    //print();

}

int main() {
    // Please write your code here.
    input();
    pro();

    int ans = dp[m];
    if(ans == INT_MAX){
        cout << -1; 
        return 0;
    }
    cout << ans;

    return 0;
}