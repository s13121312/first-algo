#include<bits/stdc++.h>
using namespace std;

/*
속한 노래가 많이 재생된 장르를 먼저 수록합니다.
장르 내에서 많이 재생된 노래를 먼저 수록합니다.
장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
*/
bool chk[10005]= {false, };
unordered_map<string, int> gr; //장르별 총 몇번 재생됬는지


bool cmp(pair<string, int>& p1, pair<string, int>& p2) {
    return p1.second > p2.second;
}

bool cmp2(pair<int, int>& p1, pair<int, int>& p2) {
    if(p1.second == p2.second)return p1.first < p2.first;
    return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for(int i=0;i<genres.size();i++) {
        gr[genres[i]] += plays[i]; 
    }
    
    vector<pair<string, int> > grv;
    for(unordered_map<string, int>::iterator it = gr.begin();it!=gr.end();it++) {
        grv.push_back({it->first, it->second});
    }
    sort(grv.begin(), grv.end(), cmp);
    
    vector<pair<int, int> >groupbygenre[105]; //고유 번호, 재생 횟수
    
    int idx = 0;
    for(auto g : grv) {
        for(int i=0;i<plays.size();i++) {
            if(chk[i])continue;
            if(genres[i] == g.first) {
                groupbygenre[idx].push_back({i, plays[i]});
                chk[i] = true;
            }
        }
        idx++;
    }
    for(int i=0;i<idx;i++) {
        sort(groupbygenre[i].begin(), groupbygenre[i].end(), cmp2);
    }
    
    for(int i=0;i<idx;i++) {
        int maxsize = 0;
        for(int j=0;j<groupbygenre[i].size();j++) {
            if(maxsize>=2)break;
            answer.push_back(groupbygenre[i][j].first);
            maxsize++;
        }
    }
    
    return answer;
}