#include<bits/stdc++.h>
using namespace std;


int n;
int dp[5005];

//상근이가 배달하는 봉지의 최소 개수를 출력한다
int main(void){

    cin >> n;

    dp[3] = 1;
    dp[5] = 1;

    for(int i=6;i<=n;i++){
        if(dp[i-3] > 0)dp[i] = dp[i-3] + 1;
        if(dp[i-5] > 0){
            if(dp[i]>0){
                dp[i] = min(dp[i], dp[i-5] + 1);
            }
            else{
                dp[i] = dp[i-5] + 1;
            }
        }
    }

    if(dp[n] != 0)cout << dp[n];
    else cout << -1;
    return 0;


}