#include <iostream>
using namespace std;
int n;
int dp[1005];

int main() {
    // Please write your code here.
    cin >> n;
    
    dp[1]=1;
    dp[2] = 2;

    for(int i=3;i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2])%10007;
    }

    cout << dp[n];

    return 0;
}