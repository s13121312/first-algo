#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[55][55];
int dp[55][55];

void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }

}

void init(){
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = INT_MIN;
        }
    }
    dp[0][0] = 1;
}

void pro(){
    init();

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){

            for(int x=0;x<i;x++){
                for(int y=0;y<j;y++){
                    if(arr[i][j] <= arr[x][y])continue;   //1번조건
                    
                    dp[i][j] = max(dp[i][j], dp[x][y] + 1);
                }
            }
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans = max(ans, dp[i][j]);
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