#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second==b.second)return a.first>b.first;
    return a.second>b.second;
}
vector<int> solution(string s) {
    vector<int> answer;
    
    map<int,int> m;
    
    string tmp;
    for(int i=1;i<s.size()-1;i++){    
        if(s[i]!='{' && s[i]!='}' && s[i]!=','){ //요런것들이 아니라면 tmp에 추가
            tmp += s[i];
            if(s[i+1]!='}' && s[i+1]!=',')continue;
            m[stoi(tmp)]++;
        }
        tmp="";
    }

    vector<pair<int,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);
    
    for(int i=0;i<v.size();i++){
        answer.push_back(v[i].first);
    }

    return answer;
}