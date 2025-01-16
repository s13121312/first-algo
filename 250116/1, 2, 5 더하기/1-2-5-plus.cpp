#include <bits/stdc++.h>
using namespace std;

int arr[] = {1,2,5};
int dp[1005];
int n;

void input(){
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;
    dp[5] =9;
}

void pro(){

    for(int i=6;i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-5])%10007;
    }
    cout << dp[n];
}
int main() {
    // Please write your code here.
    input();
    pro();

    return 0;
}