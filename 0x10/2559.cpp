#include<bits/stdc++.h>
using namespace std;

int a[100005];
int s[100005];

int main(void){

    int n,k;
    cin >> n >> k;
    s[0]=0;
    for(int i=1;i<=n;i++){
        cin >>a[i];    
        s[i] = s[i-1] + a[i];
    }
    int m = INT32_MIN;
    for(int i=k;i<=n;i++){
        m= max(m,s[i]-s[i-k]);
    }
    cout << m;



    return 0;
}