#include<bits/stdc++.h>
using namespace std;

int cnt_0[43];
int cnt_1[43];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    cnt_0[0]=1;
    cnt_0[1]=0;
    cnt_1[0]=0;
    cnt_1[1]=1;
    for(int i=2;i<=40;i++){
        cnt_0[i]=cnt_0[i-2]+cnt_0[i-1];
        cnt_1[i]=cnt_1[i-2]+cnt_1[i-1];
    }
    for(int i=0;i<t;i++){
        int k;
        cin >> k;
        cout<< cnt_0[k] << ' ' << cnt_1[k]<<'\n';
    }


    return 0;
}