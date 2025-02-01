#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    return a.first < b.first;
}
int main(void){

    stack<int> s;
    int sum =0;
    int ans =1e9;
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        int l,h;
        cin >> l >> h;
        v[i].first = l;
        v[i].second = h;
        m[l]=h;
    }

    sort(v.begin(),v.end(),cmp);

    int max_h=0;
    //2~16
    for(int i=v[0].first;i<=v[n-1].first+1;i++){
        if(s.empty()){
            max_h = m[i];
            s.push(m[i]);
        }
        if(max_h < m[i]){
            max_h = m[i];
            s.push(m[i]);
        }
        else{

        }
        

    }



    return 0;
}