#include <bits/stdc++.h>
using namespace std;

int board[502][502] = {
    0,
};
bool visit[502][502];

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    queue<pair<int, int>> Q;
    int pn = 0;      // 그림 개수
    int max_wth = 0; // 가장 넓은 그림의 넓이
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] != 1 || visit[i][j] != 0)
                continue;
            visit[i][j] = 1; // 방문했다 표시
            Q.push({i, j});  // 큐에 넣고
            pn++;            // 그림 개수 증가
            int wth = 0;
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();
                wth++;
                if(max_wth < wth)
                {
                    max_wth = wth;
                }

                for (int k = 0; k < 4; k++)
                {
                    int nx = cur.first + dir[k][0];
                    int ny = cur.second + dir[k][1];

                    if (board[nx][ny] != 1 || visit[nx][ny])
                        continue; // 새로간곳이 길이아니거나 방문했을때
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    visit[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }

    cout << pn << '\n' << max_wth;
    return 0;
}