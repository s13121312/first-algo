#include <iostream>
using namespace std;

int n;
int ans = 0;
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

void pro(){
    if(n == 1)ans = arr[0][0];
    dp[0][0] = arr[0][0];

    for(int i=1;i<n;i++){
        dp[i][0] = min(dp[i-1][0], arr[i][0]);
    }

    for(int i=1;i<n;i++){
        dp[0][i] = min(dp[0][i-1], arr[0][i]);
    }


    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            int tmp = max(min(dp[i-1][j], arr[i][j]), min(dp[i][j-1], arr[i][j]));
            ans = max(ans, tmp);
            //cout << ans << '\n';
        }
    }
    
    cout << ans;
}


int main() {
    // Please write your code here.
    input();
    pro();

    return 0;
}