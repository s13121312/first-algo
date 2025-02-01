//다시 풀기

#include<bits/stdc++.h>
#define mod 1000000000
using namespace std;

int d[105][10]; //d[i][j]는 길이가i이고 j로 끝나는 수

int main(void){

    int n;
    cin >> n;

    for(int i=0;i<10;i++){
        d[1][i]=1;
    }

    for(int i=2;i<=n;i++){
        for(int j=0;j<=9;j++){
            if(j==0){
                d[i][j]=d[i-1][j+1];
            }
            else if(j==9){
                d[i][j]=d[i-1][j-1];
            }
            else{
                d[i][j]=d[i-1][j-1]+d[i-1][j+1];
            }
            d[i][j]=d[i][j]%mod;
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum = (sum+d[n][i])%mod;
    }
    cout << sum;
    return 0;
}