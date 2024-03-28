#include<bits/stdc++.h>
using namespace std;


vector<pair<int,pair<int,int>>> v;
int num[102];

int main(void)
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c,{a,b}});
    }

    sort(v.begin(),v.end(),greater<pair<int,pair<int,int>>>());

    int a=0;
    for(int i=0;i<n;i++)
    {
        if(num[v[i].second.first]>=2)continue;
        a++;
        num[v[i].second.first]++;
        cout << v[i].second.first << ' ' << v[i].second.second<<'\n';
        if(a>=3)break;
    }





    


    return 0;
}