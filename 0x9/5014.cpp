#include<bits/stdc++.h>
using namespace std;
//총 F층으로 이루어진 고층 건물에 사무실이 있고, 
//스타트링크가 있는 곳의 위치는 G층이다. 
//강호가 지금 있는 곳은 S층이고, 
//이제 엘리베이터를 타고 G층으로 이동

int f,s,g,u,d;
int visit[1000005];


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> f >> s >> g >> u >> d;
    
    fill(visit+1, visit+f+1 ,-1);//1층~f층 -1로세팅
    queue<int> Q;
    visit[s] = 0;
    Q.push(s);

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for(int nxt: {cur+u,cur-d})
        {
            
            if(nxt<=0 || nxt>f  || visit[nxt] != -1) continue;
            // 이미간곳을 또 체크해버리면 최솟값이 달라지기에
            visit[nxt] = visit[cur]+1;
            Q.push(nxt); 
        }
    }
    if(visit[g] == -1){
        cout<< "use the stairs";
    }
    else{
        cout << visit[g];
    }
    

}