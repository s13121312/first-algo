#include<bits/stdc++.h>
using namespace std;

int a[100005];
int d[100005]; //i번째를 포함하는 최대인연속합이라 두자. 

int main(void){

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    d[0]=a[0];
    for(int i=1;i<n;i++){
        d[i]=max(d[i-1]+a[i], a[i]);
    }
    int m=-999999999;
    for(int i=0;i<n;i++){
        if(m<d[i]){
            m=d[i];
        }
    }
    cout<<m;

    return 0;
}