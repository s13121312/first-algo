//어렵다

#include<bits/stdc++.h>
using namespace std;

int d[100005]; //합이 !원이 되도록 하는 경우의수
int a[10005];

int main(void){

    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    d[0]=1; //
    for(int i=0;i<n;i++){ //n번 반복해라(동전 종류만큼 반복)
        for(int j=a[i];j<=k;j++){
            d[j] += d[j - a[i]];
        }
        
    }

    cout << d[k];



    return 0;
}