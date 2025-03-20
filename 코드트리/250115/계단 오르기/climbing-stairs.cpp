#include <iostream>
using namespace std;

int dp[1005];
int n;

void pro(){
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for(int i=4;i<=n;i++){
        dp[i] = (dp[i-2] + dp[i-3])%10007;
    }
    cout << dp[n];

}

int main() {
    // Please write your code here.
    cin >> n;
    pro();

    return 0;
}