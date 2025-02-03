#include <bits/stdc++.h>
using namespace std;

int n, arr[100005];
int dp[100005];

void input() {
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
}

void init() {
    for(int i=1;i<=n;i++){
        dp[i] = INT_MIN;
    }
}

void pro() {

    init();
    dp[1] = arr[1];
    for(int i=2;i<=n;i++) {
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
    }

    int ans= INT_MIN;
    for(int i=1;i<=n;i++){
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

int main() {
    // Please write your code here.
    input();
    pro();

    return 0;
}