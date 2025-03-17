#include <bits/stdc++.h>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    vector<string> v1;
    vector<string> v2;
    
    for(int i=0;i<str1.size();i++) {
        if(str1[i] >= 'a' && str1[i]<='z' || str1[i]>='A'&& str1[i]<='Z') {
            str1[i] = tolower(str1[i]);
        }
    }
    for(int i=0;i<str2.size();i++) {
        if(str2[i] >= 'a' && str2[i]<='z' || str2[i]>='A'&& str2[i]<='Z') {
            str2[i] = tolower(str2[i]);
        }
        
    }
    
    
    for(int i=0;i<str1.size()-1;i++) {
        string tmp;
        bool chk = true;
        for(int j=i;j<=i+1;j++) {
            if(str1[j]>='a' && str1[j] <= 'z') {
                tmp += str1[j];
            } else{
                chk = false;
                break;
            }
        }
        if(chk)v1.push_back(tmp);
    }
    
    for(int i=0;i<str2.size()-1;i++) {
        string tmp;
        bool chk = true;
        for(int j=i;j<=i+1;j++) {
            if(str2[j]>='a' && str2[j] <= 'z') {
                tmp += str2[j];
            } else{
                chk = false;
                break;
            }   
            
        }
        if(chk)v2.push_back(tmp);
    }
    
    // for(auto v : v1)cout << v << ' ';
    // cout << '\n';
    // for(auto v : v2)cout << v << ' ';
    
    
    unordered_map<string,int> um1;
    unordered_map<string,int> um2;
    
    for(auto z : v1) {
        um1[z]++;
    }
    for(auto z : v2) {
        um2[z]++;
    }
    
    int inter = 0; //교집합
    float total = 0; //합집합
    for(unordered_map<string,int>::iterator it =um1.begin();it!=um1.end();it++) {
        //교집합
        if(um2[it->first] > 0) {
            inter += min(um1[it->first], um2[it->first]);
            total += max(um1[it->first], um2[it->first]);
        }
        else {  //없으면
            total += um1[it->first];
        }
    }
    for(unordered_map<string,int>::iterator it =um2.begin();it!=um2.end();it++) {
        //교집합
        if(um1[it->first] > 0) continue;
        total += um2[it->first];
        
    }
    
    cout << inter << ' '<< total;
    if(inter == 0 && total == 0)return 65536;
    
    
    int a = (inter/total)*65536;
    cout<< a;
    
    
    
    
    return a;
}