#include<bits/stdc++.h>
using namespace std;

int main(void){

    int n, k;
    cin >> n >> k;
    int result=n;
    if(k==0){
        result=1;
        cout << result;
        return 0;
    }

    for(int i=n-1;i>n-k;i--){
        result*=i;
    }

    for(int i=k;i>=1;i--){
        result/=i;
    }

    cout << result;
    return 0;
}