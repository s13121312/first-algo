#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
bool vis[10];


void dfs(int cur){
    if(cur == n+1){
        for(auto x: v){
            cout << x << ' ';
        }
        cout << '\n';
    }


    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        v.push_back(i);
        vis[i] = true;
        dfs(cur+1);
        vis[i] = false;
        v.pop_back();
    }

}

int main() {
    // 여기에 코드를 작성해주세요.
    
    cin >> n;
    dfs(1);
    
    return 0;

    
}