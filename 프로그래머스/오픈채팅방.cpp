#include<bits/stdc++.h>
#include<sstream>
#include<map>
using namespace std;




vector<string> solution(vector<string> record) {
    vector<string> answer;

    vector<pair<string,string>> v; // 명령어와 uid 저장
    map<string,string> m; //uid와 nickname저장하는 map

 
    for(int i=0;i<record.size();i++){
        vector<string> info;
        istringstream iss(record[i]);
        string s;

        while (iss >> s)
        {
            info.push_back(s);    
        }
        if(info[0]=="Enter"){
            m[info[1]] = info[2];
            v.push_back(make_pair("Enter",info[1]));
        }
        else if(info[0]=="Change"){
            m[info[1]] = info[2];
            v.push_back({"Change",info[1]});
        }
        else{
            v.push_back({"Leave",info[1]});
        }
    }

    for(int i=0;i<v.size();i++){
        if(v[i].first=="Leave"){
            answer.push_back(m[v[i].second]+"님이 나갔습니다.");
        }
        if(v[i].first=="Enter"){
            answer.push_back(m[v[i].second]+"님이 들어왔습니다.");
        }
    }

    
    return answer;
}