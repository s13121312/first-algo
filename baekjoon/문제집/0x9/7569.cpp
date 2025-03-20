#include <bits/stdc++.h>
using namespace std;

typedef struct 
{
    int x,y,z;
}Position;


int board[102][102][102];
int dist[102][102][102];

int dir[6][3]={{0,0,1},{1,0,0},{0,1,0},{-1,0,0},{0,-1,0},{0,0,-1}};

int main(void)
{
    int m,n,h;

    cin >> m >> n >> h;
    queue<Position> Q;

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                cin >> board[j][k][i];
                if(board[j][k][i]==1)
                {
                    Q.push({j,k,i});
                }
                if(board[j][k][i]==0)
                {
                    dist[j][k][i] = -1;
                }
            }
        }
    }

    while (!Q.empty())
    {
        Position cur = Q.front();
        Q.pop();
        for(int i=0;i<6;i++)
        {
            int nx = cur.x + dir[i][0];
            int ny = cur.y + dir[i][1];
            int nz = cur.z + dir[i][2];
            if(nx<0 || nx>=n || ny<0 || ny >=m || nz<0 || nz>=h) continue;
            if(dist[nx][ny][nz] >= 0 || board[nx][ny][nz] == -1) continue;
            
            dist[nx][ny][nz] = dist[cur.x][cur.y][cur.z] + 1;
            Q.push({nx,ny,nz});
        }
    }
    
    int ans=0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                if(dist[j][k][i] == -1)
                {
                    cout << "-1";
                    return 0;
                }
                ans = max(ans,dist[j][k][i]);
            }
        }
    }

    cout << ans;


    return 0;
}