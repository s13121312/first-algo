#include<bits/stdc++.h>
using namespace std;


int main(void){
    unordered_map<string, string> m1;
    unordered_map<string,string> m2;

    vector<string> ans;
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string input;
        cin >> input;
        m1[input] = to_string(i+1);
        m2[to_string(i+1)] = input;
    }

    for(int i=0;i<m;i++){
        string s;
        cin >> s;
        if(s[0]>='1' && s[0]<='9'){
            ans.push_back(m2[s]);
        }
        else{
            ans.push_back(m1[s]);
        }
    }

    for(auto s : ans){
        cout << s << '\n';
    }

    return 0;
}