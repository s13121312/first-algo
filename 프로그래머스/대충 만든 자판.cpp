#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    unordered_map<char,int> m;
    for(int i=0;i<keymap.size();i++){
        for(int j=0;j<keymap[i].size();j++){
            if(m.find(keymap[i][j]) == m.end()){
                m[keymap[i][j]]=j+1;
            }
            else{ // 이미 넣은 놈의 번호가 새로 들어오는 놈보다 느릴때
                if(m[keymap[i][j]] >= j+1){
                    m[keymap[i][j]] = j+1;
                }
            }
        }
    }

    for(int i=0;i<targets.size();i++){
        int cnt=0;
        for(int j=0;j<targets[i].size();j++){
            if(m.find(targets[i][j]) == m.end()){
                cnt= -1;
                vector<int> tmp;
                answer.push_back(cnt);
                break;       
            }
            else{
                cnt = cnt + m[targets[i][j]];
            }
        }
        if(cnt != -1)answer.push_back(cnt);
    }
 
    return answer;
}