#include<bits/stdc++.h>
using namespace std;

int n,m,g,r;
int board[55][55];//0은 호수, 1은 배양액을 뿌릴 수 없는 땅, 2는 배양액을 뿌릴 수 있는 땅
bool visit[55][55];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> Q;

int ans=0;

void bfs(int x,int y){
    visit[x][y]=true;
    Q.push({x,y});
    while (!Q.empty())
    {
        pair<int,int> cur = Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(visit[nx][ny] || board[nx][ny]==1) continue;
            Q.push({nx,ny});
            visit[nx][ny]=true;
        }
    }
    
    
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>n >> m >> g >>r;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> board[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]==2)
            {
                //시작점
                Q.push({i,j});
                bfs(i,j);
            }
        }
    }
    return 0;
}