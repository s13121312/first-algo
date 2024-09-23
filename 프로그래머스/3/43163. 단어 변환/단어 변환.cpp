#include<bits/stdc++.h>
using namespace std;

int answer = 0x7f7f7f7f;
bool vis[55];

bool chk(string a, string b){
    int cnt = 0;
    for(int i=0;i<a.size();i++){
        if(a[i] != b[i])cnt++;
    }
    if(cnt == 1)return true;
    return false;
}

//chk는true인것만 dfs돌리기


void dfs(int cur, string tmp, string target, vector<string> words){


    if(tmp == target){
        answer = min(answer, cur);
    }

    for(int i=0;i<words.size();i++){
        if(!vis[i] && chk(tmp, words[i])){
            vis[i] = true;
            dfs(cur+1, words[i], target, words);
            vis[i] = false;
        }
    }
}


int solution(string begin, string target, vector<string> words) {
    
    
    dfs(0, begin, target, words);

    if(answer == 0x7f7f7f7f)return 0;
    return answer;
}