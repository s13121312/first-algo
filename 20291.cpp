#include<bits/stdc++.h>
using namespace std;


bool cmp(const pair<string, int> &a, const pair<string, int> &b){
    return a.first<b.first;
}

int main(void){

    int n;
    cin >> n;
    unordered_map<string,int> m;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        bool check = false;
        string tmp;
        for(int j=0;j<str.size();j++){
            
            if(str[j]=='.'){
                check=true;
                continue;
            }
            if(check){
                tmp+=str[j];
            }
        }
        m[tmp]++;
    }

    vector<pair<string,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<v.size();i++){
        cout << v[i].first << ' ' <<v[i].second << '\n';
    }
    return 0;
}