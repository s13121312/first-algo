#include<bits/stdc++.h>
using namespace std;


int n,k;
int im[105][2]; // weight, value
int dp[105][100005]; //dp[i][j]에서 i는 물품 

int main(void){

    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> im[i][0] >> im[i][1];
    }

    for(int i=1;i<=n;i++){
        for(int cw=1;cw<=k;cw++){
            if(cw >= im[i][0]){ //i번째를 넣을수있으면
                dp[i][cw] = max(dp[i-1][cw], dp[i][cw - im[i][0]] + im[i][1]);
            }
            else{
                dp[i][cw] = dp[i-1][cw];
            }
            // i번째물건까지 넣었을때 최댓값은(dp[i][j]) i번째것을 넣었을때와 안넣을때
        }
    }

    cout << dp[n][k];
    return 0;
}