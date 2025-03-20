#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[25];
int ans = 0;
vector<int> v;

void input(){
    cin >> n >>m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
}

//xor하는 함수
int calc(){
    int res = v[0];
    for(int i=1;i<v.size();i++){
        res =  res ^ v[i];
    }
    return res;
}

void pro(int depth, int num_idx){
    
    if(!v.empty()){
        if(v.size() == m)ans = max(ans, calc());
    }
    //cout << ans << ' ';

    for(int i=depth;i<n;i++){
        v.push_back(arr[i]);
        pro(depth+1, i+1);
        v.pop_back();
    }
}

int main() {
    // Please write your code here.
    input();
    pro(0, 0);
    cout << ans;


    return 0;
}