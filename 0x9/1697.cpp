#include <bits/stdc++.h>
using namespace std;

int visit[100005];

int main(void)
{

    int n, k;
    cin >> n >> k; // n이 시작점 k 가 목적지

    queue<int> Q;

    for (int i = 0; i < 100005; i++)
    {
        visit[i] = -1;
    }

    visit[n] = 0; // n이 시작점
    Q.push(n);

    while (!Q.empty()) //while(visit[k]==-1)
    {
        int cur = Q.front();
        Q.pop();

        for(int nxt : {cur-1,cur+1,2*cur})
        {
            if(nxt<0 || nxt >100000) continue;
            if(visit[nxt] != -1) continue;
            visit[nxt] = visit[cur] + 1;
            Q.push(nxt);
        }
        // for (int i = 0; i < 2; i++)
        // {
        //     int nx = cur + dir[i];
        //     if (nx < 0 || nx > 100000)
        //         continue;
        //     if (visit[nx] >= 0)
        //         continue;

            
        //     visit[nx] = visit[cur] + 1;
        //     Q.push(nx);
        // }

        // int nx = 2 * cur;
        // if (nx < 0 || nx >= 100000)
        //     continue;
        // if (visit[nx] >= 0)
        //     continue;
        // int ans=0;
        // if(nx == k)
        // {
        //     ans = min(ans,visit[cur]);
        //     cout << ans;
        //     return 0;
        // }
        // visit[nx] = visit[cur] + 1;
        // Q.push(nx);
    }
    cout<< visit[k];
    return 0;
}