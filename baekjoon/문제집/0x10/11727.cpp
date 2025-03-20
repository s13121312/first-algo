#include<bits/stdc++.h>
using namespace std;

int d[1005][5];
int ans[1005];

int main(void){

    int n;
    cin >> n;

    d[1][0]=1;
    d[1][1]=0;
    d[1][2]=0;
    d[2][0]=1;
    d[2][1]=1;
    d[2][2]=1;
    ans[1]=1;
    ans[2]=3;
    for(int i=3;i<=n;i++){
        d[i][0]=(d[i-1][0]+d[i-1][1]+d[i-1][2])%10007;
        d[i][1]=(d[i-2][0]+d[i-2][1]+d[i-2][2])%10007;
        d[i][2]=(d[i-2][0]+d[i-2][1]+d[i-2][2])%10007;
        ans[i]=(d[i][0]+d[i][1]+d[i][2])%10007;
    }

    cout << ans[n];

    return 0;
}