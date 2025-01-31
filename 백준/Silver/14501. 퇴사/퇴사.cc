#include<bits/stdc++.h>
using namespace std;

int n;
int t[20], p[20];
int dp[20]; //i번째 일을 할때 얻을 수 있는 최대 수익

void input(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> t[i] >> p[i];
        t[i] = i + t[i] -1;
    }
}

void init(){
    for(int i=1;i<=n;i++){
        dp[i] = INT_MIN;
    }
    dp[0] = 0;
}

void pro(){

    for(int i=1;i<=n;i++){
        if(t[i] > n)continue;
        for(int j=0;j<i;j++){
            if(t[j] < i){
                dp[i] = max(dp[i], dp[j] + p[i]);
            }
        }
    }

    int maxVal = 0;
    for(int i=1;i<=n;i++){
        maxVal = max(maxVal, dp[i]);
    }
    cout << maxVal;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    pro();
    
    return 0;
}