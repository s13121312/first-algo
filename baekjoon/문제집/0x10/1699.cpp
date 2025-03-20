#include<bits/stdc++.h>
using namespace std;


int d[1000005];

int main(void){

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        d[i]=i;
        for(int j=1;j*j<=i;j++){
            d[i] = min(d[i-j*j]+1,d[i]);
        }
    }
    

    cout << d[n];

    return 0;
}