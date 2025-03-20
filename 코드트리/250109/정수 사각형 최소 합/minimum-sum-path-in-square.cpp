#include <iostream>
using namespace std;
int n;
int arr[105][105];
int dp[105][105];

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
}

void init(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = 0;
        }
    }
}

void pro(){
    dp[0][n-1] = arr[0][n-1];
    for(int i=n-2;i>=0;i--){
        dp[0][i] = dp[0][i+1]+ arr[0][i];
    }

    for(int i=1;i<n;i++){
        dp[i][n-1] = dp[i-1][n-1] + arr[i][n-1];
    }

    for(int i=1;i<n;i++){
        for(int j=n-2;j>=0;j--){
            dp[i][j] = min(dp[i][j+1], dp[i-1][j]) + arr[i][j];
        }
    }

    cout << dp[n-1][0];
}
void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main() {
    // Please write your code here.
    input();
    pro();
    //cout << '\n';
    //print();

    return 0;
}