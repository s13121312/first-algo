#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<int> keyword;
    unordered_map<string,int> mapp;

    for(int i=0;i<n;i++){
        string word;
        cin >> word;
        mapp[word]++;
    }
    
    for(int i=0;i<m;i++){
        string word;
        cin >> word;
        istringstream ss(word);
        string token;
        while (getline(ss,token,','))
        {
            if(mapp.find(token) != mapp.end()){
                mapp.erase(token);
            }
        }
        cout<< mapp.size()<<'\n';
    }
}