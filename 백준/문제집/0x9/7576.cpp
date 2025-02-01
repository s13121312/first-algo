#include <bits/stdc++.h>
using namespace std;


int board[1005][1005]={0,};
int dist[1005][1005];

int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,n;
    cin >> m >> n; // m은 가로(y) n은 세로(x)
    queue<pair<int, int> > Q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> board[i][j];
            if(board[i][j]==1) //시작점이 여러개일 수잇으니 될수잇는시작점을 큐에 다 넣음
            {
                Q.push({i,j});
            }
            if(board[i][j]==0) 
            {
                dist[i][j] = -1; 
            }
        }
    }

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dir[i][0];
            int ny = cur.second + dir[i][1];
            if(nx<0 || nx >=n || ny<0 || ny >=m) continue;
            if(dist[nx][ny] >= 0 || board[nx][ny] == -1) continue; // board가 -1인곳은 못가니까 제외, dist가 음수인곳만 가기
            
            dist[nx][ny]=dist[cur.first][cur.second] +1;
            Q.push({nx,ny});

        }
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dist[i][j] == -1) //안익은 토마토가 있을때 
            {
                cout << "-1";
                return 0;
            }
            ans = max(ans,dist[i][j]);
        }
    }
    
    cout << ans;

    return 0;
}