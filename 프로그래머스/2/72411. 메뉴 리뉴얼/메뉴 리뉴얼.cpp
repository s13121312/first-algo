#include <bits/stdc++.h>
#include <vector>

using namespace std;
map<string, int> mp;
//55m

//wx, xw 처리를 어떻게?? -> 미리 정렬

void dfs(string& o, vector<bool>& vis, int depth, int idx, string cur) {
    if(depth == o.size()) {
        mp[cur]++;
        return;
    }
    if(cur.size() >= 2) {
        mp[cur]++;
    }
    
    
    for(int i=idx;i<o.size();i++) {
        if(vis[i])continue;
        vis[i] = true;
        dfs(o, vis, depth+1, i+1, cur+o[i]);
        vis[i] =false;
    }
    
}

//최소 2가지 이상의 단품메뉴로 구성
//최소 2명 이상의 손님으로부터 주문된 단품메뉴 조합에 대해서만
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i=0;i<orders.size();i++){
        sort(orders[i].begin(), orders[i].end());
    }
    
    for(auto o : orders) {
        vector<bool> vis(o.size()+1, false);
        
        dfs(o, vis, 0, 0, "");
    }
    
    for(auto c : course) {
        int maxuses =0;
        for(map<string,int>::iterator it = mp.begin();it!=mp.end();it++) {
            if(it->second >=2 && (int)it->first.size() == c) {
                maxuses = max(maxuses, it->second);
            }
            //if(it->first.size() > c)break;
        }
        
        for(map<string,int>::iterator it = mp.begin();it!=mp.end();it++) {
            if((int)it->first.size() == c && it->second == maxuses) {
                answer.push_back(it->first);
            }
            //if(it->first.size() > c)break;
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}