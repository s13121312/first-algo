#include<bits/stdc++.h>
using namespace std;

int c[1005][1005];

int main(void){

    
    

    for(int i=1;i<=1000;i++){
        c[i][0]=1;
        c[i][i]=1;
        for(int j=1;j<i;j++){
            c[i][j] = c[i-1][j]%10007 + c[i-1][j-1]%10007;
        }
    }

    int n, k;
    cin >> n >> k;
    cout << c[n][k];
    return 0;
}