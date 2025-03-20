#include<bits/stdc++.h>
using namespace std;

int a[105];
int d[10005];
int main(void){

    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    fill(d, d+10005, 10005);
    d[0]=0;
    for(int i=0;i<n;i++){
        for(int j =a[i];j<=k;j++)
        {
            d[j] = min(d[j-a[i]]+1,d[j]);
        }
    }

    cout << (d[k] == 10005 ? -1 :d[k])<< '\n';
    return 0;
}