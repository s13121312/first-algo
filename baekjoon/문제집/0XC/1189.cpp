#include <bits/stdc++.h>
using namespace std;

int r, c, k;
string maze[10];
bool visit[10][10];
int ans = 0;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

void dfs(int x, int y, int len);

int main(void)
{

    cin >> r >> c >> k;
    for (int i = 0; i < r; i++)
    {
        cin >> maze[i];
    }

    // 왼쪽아래에서 시작 오른쪽위가 도착
    visit[r - 1][0] = true;
    dfs(r - 1, 0, 1);

    cout << ans;
    return 0;
}

void dfs(int x, int y, int len)
{

    if (x == 0 && y == c - 1)
    {
        if (len == k)
        {
            ans++;   
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c || visit[nx][ny] || maze[nx][ny] == 'T')
            continue;

        visit[nx][ny] = true;
        dfs(nx, ny, len + 1);
        visit[nx][ny] = false;
    }
}