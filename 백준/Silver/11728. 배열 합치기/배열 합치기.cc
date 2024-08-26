//11728
#include<bits/stdc++.h>
using namespace std;

int n, m;
int arra[1000005];
int arrb[1000005];
vector<int> v;

void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++)cin >> arra[i];
    for(int i=0;i<m;i++)cin >> arrb[i];

}

void pro(){

    int l = 0, r = 0;
    while (l<n && r<m)
    {
        if(arra[l]>arrb[r]){
            v.push_back(arrb[r]);
            r++;
        }else{
            v.push_back(arra[l]);
            l++;
        }
    }

    while (l<n)
    {
        v.push_back(arra[l]);
        l++;
    }
    while (r<m)
    {
        v.push_back(arrb[r]);
        r++;
    }

    for(auto cur : v){
        cout << cur << ' ';
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    input();
    pro();

    return 0;
}