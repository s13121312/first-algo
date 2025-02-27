#include <bits/stdc++.h>
#include <vector>

using namespace std;

map<int, int> mp;

bool cmp(pair<int,int> p1, pair<int,int> p2) {
    return p1.second>p2.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    string num;
    for(int i=2;i<s.size()-1;i++) {
        if(s[i] == '{' || s[i] == '}' || s[i] == ',') {
            if(!num.empty()){
                mp[stoi(num)]++;
            }
            num.clear(); 
        } 
        else num += s[i];
    }
    vector<pair<int,int>> v;
    for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++) {
        v.push_back({it->first, it->second});
    }
    
    sort(v.begin(),v.end(),cmp);
    for(auto x: v) {
        answer.push_back(x.first);
    }
    return answer;
}