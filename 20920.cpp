#include<bits/stdc++.h>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(const pair<string,int> &a, const pair<string,int> &b){

    if(a.second==b.second){
        if(a.first.length() == b.first.length()){
            return a.first < b.first;
        }
        return a.first.length() >b.first.length();
    }
    return a.second>b.second;
    
}

int main(void){
    
    int n,m;
    cin >> n >> m;

    unordered_map<string,int> match;
    
    //m이상인것만 외운다 m보다 작은것들버림
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if(str.size()>=m){
            match[str]++;
        }
    }

    vector<pair<string,int>> word(match.begin(),match.end());
    sort(word.begin(),word.end(),cmp);

    for(int i=0;i<word.size();i++){
        cout << word[i].first << '\n';
    }
    return 0;
}