#include<bits/stdc++.h>
using namespace std;

long long d[100][2];
long long sum[100];


int main(void){

    int n;
    cin >> n;

    d[1][0]=0;
    d[1][1]=1;
    d[2][0]=1;
    d[2][1]=0;
    sum[1]=1;
    sum[2]=1;
    for (int i = 3; i <= n; i++)
    {
        d[i][0]=d[i-1][0]+d[i-1][1];
        d[i][1]=d[i-1][0];
        sum[i]=d[i][0]+d[i][1];
    }
    
    cout<<sum[n];

    return 0;
}