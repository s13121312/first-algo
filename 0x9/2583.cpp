#include <bits/stdc++.h>
using namespace std;

int board[102][102];
bool visit[102][102];

int dx[4] = {1, 0, -1,0};
int dy[4] = {0, 1, 0,-1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, n, k;
    cin >> m >> n >> k;
    while (k--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; i++)
        {
            for (int j = x1; j < x2; j++)
            {
                board[i][j] = 1;
            }
        }
    }
    vector<int> ans;
    int num = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1 || visit[i][j])
                continue;
            queue<pair<int, int>> Q;
            visit[i][j] = true;
            Q.push({i, j});
            num++;
            int width = 0;
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();
                width++;
                for (int k = 0; k < 4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;
                    if (visit[nx][ny] || board[nx][ny] == 1)
                        continue;
                    visit[nx][ny] = true;
                    Q.push({nx, ny});
                    
                }
            }
            ans.push_back(width);
        }
    }
    sort(ans.begin(), ans.end());

    cout << num << '\n';
    for (int i : ans)
    {
        cout << i << ' ';
    }

    return 0;
}