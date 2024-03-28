#include <bits/stdc++.h>
using namespace std;

int board[52][52];
bool visit[52][52];
queue<pair<int,int>> Q;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int m,n,k;

void bfs(int x, int y){
    visit[x][y]=true;
    Q.push({x,y});
    
    while (!Q.empty())
    {
        pair<int,int> cur = Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = cur.first+dir[i][0];
            int ny = cur.second+dir[i][1];
            if(nx<0 || nx>=n || ny<0 || ny>= m) continue;
            if(board[nx][ny]!=1 || visit[nx][ny]) continue;
            visit[nx][ny] = true;
            Q.push({nx,ny});
        }    
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    
    while (t--)
    {
        cin >> m >> n >> k;
        int x,y;
        for(int i=0;i<k;i++)
        {
            cin >> x >> y;
            board[y][x] = 1;
        }
        int ans =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == 1 && !visit[i][j])
                {
                    bfs(i,j);
                    ans++;
                }
            }
        }
        cout << ans <<'\n';
        for(int i=0;i<n;i++)
        {
            fill(board[i],board[i]+m,0);
            fill(visit[i],visit[i]+m, false);
        }
    }
    return 0;
}