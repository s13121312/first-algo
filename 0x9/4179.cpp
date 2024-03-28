#include <bits/stdc++.h>
using namespace std;

string board[1024];
int dist1[1024][1024]; //지훈
int dist2[1024][1024]; //불

int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int main(void)
{
    int r, c;
    cin >> r >> c; // r은 가로 c는 세로

    queue<pair<int, int>> Q1;
    queue<pair<int, int>> Q2;

    for (int i = 0; i < c; i++)
    {
        cin >> board[i];
    }

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            dist1[i][j] = -1;
            dist2[i][j] = -1;
        }
    }

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if (board[i][j] == 'J') // 지훈이
            {
                dist1[i][j] = 0;
                Q1.push({i, j});
            }
            if (board[i][j] == 'F') // 불
            {
                dist2[i][j] = 0;
                Q2.push({i, j});
            }
        }
    }


    while (!Q2.empty()) // 불
    {
        pair<int, int> cur2 = Q2.front();
        Q2.pop();

        for(int i=0;i<4;i++)
        {
            int nx = cur2.first + dir[i][0];
            int ny = cur2.second + dir[i][1];
            if(nx < 0 || nx>=c || ny<0 || ny>=r) continue;
            if(board[nx][ny] == '#' || dist2[nx][ny]>=0) continue;
            
            dist2[nx][ny] = dist2[cur2.first][cur2.second] + 1;
            Q2.push({nx,ny});
        }
    }

    while (!Q1.empty()) 
    {
        pair<int, int> cur1 = Q1.front();
        Q1.pop();

        for(int i=0;i<4;i++)
        {
            int kx = cur1.first + dir[i][0];
            int ky = cur1.second + dir[i][1];
            if(kx < 0 || kx>=c || ky<0 || ky>=r) {//범위를 벗어남 = 탈출했다.
                cout << dist1[cur1.first][cur1.second] + 1;
                return 0;
            }
            if(board[kx][ky] == '#' || dist1[kx][ky]>=0) continue;
            //이부분 이해가 안감
            //다음에 가려는곳에 불이있으면 안되고  지훈이 dist보다 불이 더 커야됨 그래야 안전하게 이동이가능함 불이
            if(dist2[kx][ky] != -1 || dist2[kx][ky] <= dist1[cur1.first][cur1.second]+1) continue;
            dist1[kx][ky] = dist1[cur1.first][cur1.second] + 1;
            Q1.push({kx,ky});
        }
    }
    cout << "IMPOSSIBLE";

}