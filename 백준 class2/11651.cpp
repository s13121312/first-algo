#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2){
    if(p1.second == p2.second){
        return p1.first < p2.first;
    }
    else{
        return p1.second < p2.second;
    }
}

int main(void)
{
    int n,x,y;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(),v.end(),cmp);


    for(int i=0;i<n;i++)
    {
        cout << v[i].first << " " << v[i].second <<'\n';
    }
    return 0;
}