#include <bits/stdc++.h>
using namespace std;

string board[26];
bool visit[26][26];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    for (int i = 0; i < n; i++)
    {
        fill(visit[i], visit[i] + n, false);
    }

    queue<pair<int, int>> Q;
    int num = 0; // 총 단지 개수
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // if (board[i][j] == '0' || visit[i][j])
            //     continue;
            if (board[i][j] == '1' && visit[i][j] == false)
            {
                num++;
                visit[i][j] = true;
                Q.push({i, j});
                int count = 0;
                while (!Q.empty())
                {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    count++;
                    for (int d = 0; d < 4; d++)
                    {
                        int nx = cur.first + dx[d];
                        int ny = cur.second + dy[d];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        if (board[nx][ny] == '0' || visit[nx][ny])
                            continue;
                        visit[nx][ny] = true;
                        Q.push({nx, ny});
                    }
                }
                ans.push_back(count);
            }

            
        }
    }
    sort(ans.begin(), ans.end());
    cout << num << '\n';
    for (int i : ans)
    {
        cout << i << '\n';
    }

    return 0;
}
