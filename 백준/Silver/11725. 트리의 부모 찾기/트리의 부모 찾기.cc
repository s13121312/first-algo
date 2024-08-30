//11725
#include<bits/stdc++.h>
using namespace std;


vector<int> adj[100005];
int n;
int a, b;
int root = 1;
int p[100005];

void input(){

    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> a >>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

}

void bfs(int root){

    queue<int> q;
    q.push(root);

    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if(p[cur] == nxt)continue;
            
            q.push(nxt);
            p[nxt] = cur;
        }
    }

}

void pro(){

    bfs(root);
    for(int i=2;i<=n;i++){
        cout << p[i] << '\n';
    }

}

int main(){

    input();
    pro();

    return 0;
}
