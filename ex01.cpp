#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> wires;
vector<int> graph[105];
int answer = -1;

//https://webddevys.tistory.com/m/551
//다시 보고 이해해보자.

int dfs(int togo, int now, int cnt){
    
    for(int i=0;i<graph[now].size();i++){
        if(togo != graph[now][i]){
            dfs(now, graph[now][i], cnt+1);
        }
    }
    return cnt;
}

void pro(){
    
    for(auto v : wires){
        graph[v[0]].push_back(v[1]);
        graph[v[1]].push_back(v[0]);
    }

    for(auto z : wires){
        int sum = dfs(z[0], z[1], 1); //z[0]과 z[1]의 연결을 끊는다.
        
        answer = min(abs(n- sum*2), answer);
    }
}

int solution(int n, vector<vector<int>> wires) {
    
    pro();

    return answer;
}