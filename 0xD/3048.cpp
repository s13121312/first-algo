#include<bits/stdc++.h>
using namespace std;


vector<pair<char,int>> v;
int t;




int main(void)
{
    int n1,n2;
    cin >> n1 >> n2;
    string str;
    cin >> str;
    for(int i=n1-1;i>=0;i--) //right 방향은0
    {
        v.push_back({str[i],0});
    }

    cin >> str;
    for(int i=0;i<n2;i++)
    {
        v.push_back({str[i],1});
    }

    int time=0;
    cin >>t;

    while (time!=t)
    {
        for(int i=0;i<n1+n2-1;i++){
            if(v[i].second != v[i+1].second){
                swap(v[i],v[i+1]);
                i++; //01바꿨으면 12바꾸는게아니라 23바꿔야하기에
            }
            
        }
        time++;
    }

    for(int i=0;i<n1+n2;i++)
    {
        cout << v[i].first;
    }


    return 0;
}