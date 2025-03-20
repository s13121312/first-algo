#include<bits/stdc++.h>
using namespace std;


int x[1000005];
vector<int> tmp,uni;

int main(void){

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x[i];
        tmp.push_back(x[i]);
    }

    sort(tmp.begin(),tmp.end());

    //중복 제거
    
    for(int i=0;i<n;i++){
        if(i ==0 || tmp[i-1]!=tmp[i]){
            uni.push_back(tmp[i]);
        }
    }

    for(int i=0;i<n;i++){
        cout << lower_bound(uni.begin(),uni.end(),x[i])-uni.begin() << ' ';
    }

    return 0;
}