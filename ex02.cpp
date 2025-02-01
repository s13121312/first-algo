#include<bits/stdc++.h>
using namespace std;
int m =4;
int n =3;

int main(){

    for(int i=0;i<=m;i++){
        for(int j=1;j<n;j++){
            if(i >= arr[j][0]){
                dp[j][i] = max(dp[j-1][i], dp[j][i-arr[j][0]] + arr[j][1]);
            } 
            else{
                dp[j][i] = dp[j-1][i];
            }
        }
    }
    return 0;
}