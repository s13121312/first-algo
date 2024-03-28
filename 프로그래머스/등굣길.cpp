#include<bits/stdc++.h>
using namespace std;

int dp[105][105];


bool isused[105][105]={false, };

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    dp[1][1]=1;
    //m 가로
    //n 세로
    for(int i=0;i<puddles.size();i++){
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }
   
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int a=0;
            int b=0;
            if(dp[i][j] == -1)
                continue;
            if(dp[i-1][j] != -1){
                a = dp[i-1][j];
                dp[i][j] += a;
            }
             if(dp[i][j-1] != -1){
                b = dp[i][j-1];
                dp[i][j] += b;
            }
            dp[i][j] %= 1000000007;
            
        }
    }

    answer=dp[n][m];
    return answer;
}