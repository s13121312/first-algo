#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,string> &a, const pair<int,string> &b){
    return a.first<b.first;
}
int main(void){

    int n;
    cin >> n;
    vector<pair<int, string>> v;
    for(int i=0;i<n;i++){
        int a;
        string b;
        cin >> a >> b;
        v.push_back({a,b});  
    }
    stable_sort(v.begin(),v.end(),cmp);


    for(int i=0;i<n;i++){
        cout<<v[i].first<<' ' <<v[i].second<<'\n';
    }
    return 0;
}