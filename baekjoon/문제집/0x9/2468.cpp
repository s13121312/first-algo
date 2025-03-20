#include <bits/stdc++.h>
using namespace std;

int board[102][102];
bool visit[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

int maxlimit=0;
int ans = 0;

void bfs(int x, int y,int limit)
{
    visit[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (visit[nx][ny] || board[nx][ny]<=limit)
                continue;
            visit[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main(void)
{
    
    cin >> n;
    
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            maxlimit = max(board[i][j],maxlimit);
        }
    }
    
    for(int limit=0; limit<maxlimit; limit++){
        
        for(int i=0;i<n;i++)
        {
            fill(visit[i],visit[i]+n,0);
        }
        
        int safe=0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(!visit[i][j] && board[i][j]> limit)
                {
                    bfs(i,j,limit);
                    safe++;
                }
            }
        }
        ans = max(safe,ans);
        
    }
    cout << ans;
    return 0;
}