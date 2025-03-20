#include <bits/stdc++.h>
using namespace std;

string board[102]; //string 으로 처리해야함 왜냐하면 for문은 붙어있는것으로 인식하지않아서
//int로는 처리불가
int visit[102][102];

int dir[4][2]={{1, 0}, {0, 1}, {-1, 0}, {0, -1}};


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    
    for(int i=0;i<n;i++)
    {
        cin >> board[i];
    }

    queue<pair<int,int> > Q;
    
    visit[0][0]= 1; // 출발점  목적지는 n-1,m-1이다.
    Q.push({0,0}); //

    while (!Q.empty())
    {
        pair<int,int> cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dir[i][0];
            int ny = cur.second + dir[i][1];
            
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(visit[nx][ny] > 0 || board[nx][ny]!='1') continue;
            
            visit[nx][ny]= visit[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
        
    }
    cout<< visit[n-1][m-1];

    return 0;
}