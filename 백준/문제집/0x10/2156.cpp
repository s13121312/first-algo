#include<bits/stdc++.h>
using namespace std;

int a[10005];
int d[10005];

int main(void){

    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    d[1]=a[1];
    d[2]=a[1]+a[2];
    d[3]=max(max(a[1]+a[2],a[2]+a[3]),a[1]+a[3]);

    for(int i=4;i<=n;i++){
        d[i]=max(max(a[i]+d[i-2],a[i]+a[i-1]+d[i-3]),d[i-1]);
    }
    cout << d[n];
    return 0;
}