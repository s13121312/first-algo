#include <bits/stdc++.h>
using namespace std;
int arr[105];
int n, m;
int dp[10005];
int ans;

void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    dp[0] = 0;
    for(int i=1;i<=m;i++){
        dp[i] = INT_MIN;
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
            if(i >= arr[j]){
                if(dp[i-arr[j]] == INT_MIN)continue;
                dp[i] = max(dp[i] , dp[i - arr[j]] + 1);
            }
        }
    }
    //print();

    ans = dp[m];
    if(ans == INT_MIN)cout << -1;
    else{
        cout << ans;
    }
}

int main() {
    // Please write your code here.
    input();
    pro();


    return 0;
}