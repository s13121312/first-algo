#include<bits/stdc++.h>
using namespace std;

int d[1005]; //i번째까지 증가하는 부분수열 중 가장 긴것의길이
int a[1005];
int main(void){

    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        d[i]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]<a[i]) d[i]=max(d[i],d[j]+1);
        }
    }
    cout << *max_element(d+1,d+n+1);  //[)
    // int m=0;
    // for(int i=1;i<=n;i++){
    //     if(m<d[i]){
    //         m=d[i];
    //     }
    // }
    // cout <<m;

    return 0;
}