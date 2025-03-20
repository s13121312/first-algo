#include <iostream>
using namespace std;

int n;
int arr[105][105];
int dp[105][105];
int ans =0;

void init(){
    dp[0][0] = arr[0][0];

    for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][0] + arr[i][0];
    }
    for(int i=1;i<n;i++){
        dp[0][i] = dp[0][i-1] + arr[0][i];
    }


    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + arr[i][j];
        }
    }
}

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
}

void pro(){
    cout << dp[n-1][n-1];
}
int main() {
    // Please write your code here.
    input();
    init();
    pro();

    return 0;
}