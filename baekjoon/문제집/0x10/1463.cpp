// #include<bits/stdc++.h>
// using namespace std;

// int n;
// int dist[1000005];

// int main(void){

//     cin >> n;
//     fill(dist,dist+1000004,-1);
//     dist[1]=0;
//     queue<int> q;
//     q.push(1);
//     while (!q.empty())
//     {
//         int cur = q.front();
//         q.pop();
//         for(int next:{2*cur,3*cur,cur+1}){
//             if(next<=0 || next>=1000001)continue;
//             if(dist[next] != -1)continue;//방문한데를굳이또갈필요없으니
//             dist[next]=dist[cur]+1;
//             q.push(next);
//         }
//     }
    
//     cout<<dist[n];

//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;

int d[1000005];
int n;


int main(void){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[1]=0;

    for(int i=2;i<=n;i++){
        d[i]=d[i-1]+1;
        if(i%3==0)d[i]=min(d[i],d[i/3]+1);
        if(i%2==0)d[i]=min(d[i],d[i/2]+1);
    }
    cout<<d[n];

    return 0;
}