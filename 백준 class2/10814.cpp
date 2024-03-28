//stable_sort라는걸이용해야한다네 구현 못함
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    // vector<pair<int,string>> member(n);

    // for(int i=0;i<n;i++)
    // {
    //     cin >> member[i].first >> member[i].second;
    // }

    // sort(member.begin(),member.end());

    // for(int i=0;i<n;i++)
    // {
    //     cout << member[i].first << " " <<member[i].second<<'\n';
    // }

    int age[100005];
    string name[100005];
    for(int i=0;i<n;i++)
    {
        cin >> age[i] >> name[i];
    }

    for(int i=n-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(age[j]>age[j+1])
            {
                swap(age[j],age[j+1]);
                swap(name[j],name[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout << age[i] << " " << name[i]<<'\n';       
    }
    return 0;
}