#include <bits/stdc++.h>
using namespace std;

vector<int> connected[105];
vector<bool> visited;

//now와 togo를 끊었을떄 now쪽에 딸린개수
int dfs(int now , int togo){
    int cnt = 1;
    visited[now] = true;
    
    for(int next : connected[now]){
        if(visited[next] || next == togo) continue;
        cnt += dfs(next, togo);
        
    }
    
    return cnt;
}

int bfs(int v1, int v2){
    int cnt =1;
    
    queue<int> q;
    q.push(v1);
    visited[v1] = true;
    visited[v2] = true;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(auto next : connected[cur]){
            if(visited[next])continue;
            cnt++;
            visited[next] = true;
            q.push(next);
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int ans = 0x7fffffff;
    
    for(int i=0;i<wires.size();i++){
        connected[wires[i][0]].push_back(wires[i][1]);
        connected[wires[i][1]].push_back(wires[i][0]);
    }
    
    
    for(auto x: wires){
        visited = vector<bool> (n+1,false);
        int c0 = bfs(x[0], x[1]);
        int c1 = n-c0;
        ans = min(ans, abs(c1-c0));
    }
    
    
    return ans;
}