#include <bits/stdc++.h>
using namespace std;

char board[102][102]; //string 으로 쓴거랑 차이 써칭
bool visit[102][102];
int n;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
queue<pair<int, int>> q;

void bfs(int x, int y){
    visit[x][y] = true;
    q.push({x,y});
    while (!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = cur.first + dir[i][0];
            int ny = cur.second + dir[i][1];
            if(nx<0 || nx>=n|| ny<0 || ny >=n) continue;
            if(visit[nx][ny] || board[x][y] != board[nx][ny]) continue;
            visit[nx][ny] = true;
            q.push({nx,ny});
        }
    }
}

int area(){
    int cnt =0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!visit[i][j]){
                bfs(i,j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> board[i][j];
        }
    }
    int not_g = area();//적록색약 아닌사람

    //초기회 시켜줘야함 위에서 visit을 더럽혔으니
    for(int i=0;i<n;i++)
    {
        fill(visit[i],visit[i]+n,false);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]=='G') //빨,초는 같은취급해야하므로 초록색이면 빨간색으로 바꿔줌!!!!!
            {
                board[i][j] = 'R';
            }
        }
    }
    int is_g = area();

    cout << not_g <<" " << is_g;    

    return 0;
}