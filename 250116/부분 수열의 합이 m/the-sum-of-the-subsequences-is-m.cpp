#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[105];
int dp[10005];
int ans;

void input(){
    cin >>n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
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


    for(int i=0;i<n;i++){
        for(int j=m;j>=1;j--){
            if(j >= arr[i]){
                if(dp[j-arr[i]] == INT_MAX)continue;
                dp[j] = min(dp[j], dp[j-arr[i]] + 1);
            }
        }
    }
    //print();


    ans = dp[m];
    if(ans == INT_MAX)cout << -1;
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