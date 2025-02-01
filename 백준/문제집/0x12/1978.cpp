#include<bits/stdc++.h>
using namespace std;

bool func(int k){
    if(k==1) return 0;
    for(int i=2;i*i<=k;i++){
        if(k%i==0){
            return 0;
        }
    }
    return 1;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n;
    cin >> n;
    int result = 0;
    
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        if(func(k)){
            result++;
        }
    }
    cout<< result;

    return 0;
}