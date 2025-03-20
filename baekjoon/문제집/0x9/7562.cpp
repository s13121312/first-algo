#include <bits/stdc++.h>
using namespace std;

int visit[302][302];
queue<pair<int, int>> Q;
int l;
int dx[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int dy[8] = {1, -1, 1, -1, 2, 2, -2, -2};


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    int now_x, now_y;
    int dst_x, dst_y;
    while (t--)
    {
        cin >> l;
        for(int i=0;i<l;i++)
        {
            fill(visit[i],visit[i]+l,-1);
        }
        
        cin >> now_x >> now_y;
        cin >> dst_x >> dst_y;
        visit[now_x][now_y] = 0;
        Q.push({now_x, now_y});
        while (!Q.empty())
        {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int i = 0; i < 8; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(nx <0 || nx>=l || ny<0 || ny>=l)continue;
                if(visit[nx][ny]>=0)continue;
                visit[nx][ny]=visit[cur.first][cur.second] + 1;
                Q.push({nx,ny});
            }
        }
        cout << visit[dst_x][dst_y] << '\n';
    }

    return 0;
}