#include<bits/stdc++.h>
using namespace std;

int d[100005];
int t[100005];

int main(void){

    int n,k;
    cin >> n >> k;
    
    fill(d,d+100000,-1);
    queue<int> q;

    d[n]=0;
    q.push(n);

    while (!q.empty())
    {
        int cur =q.front();
        q.pop();
        for(auto nxt : {cur-1, cur+1, 2*cur}){
            if(nxt<0 || nxt >100000) continue;
            if(d[nxt]>=0) continue;
            d[nxt] = d[cur]+1;
            q.push(nxt);            
        }
    }
    
    cout << d[k];
    


    return 0;
}