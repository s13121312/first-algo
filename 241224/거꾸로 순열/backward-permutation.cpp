#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
bool chk[10];

void dfs(int cur){

    if(cur == n+1){
        for(auto x: v){
            cout << x << ' ';
        }
        cout << '\n';
    }

    for(int i=n;i>=1;i--){
        if(chk[i])continue;
        chk[i] = true;
        v.push_back(i);
        dfs(cur + 1);

        chk[i] = false;
        v.pop_back();

    }
}

int main() {
    
    cin >> n;

    dfs(1);


    return 0;
}