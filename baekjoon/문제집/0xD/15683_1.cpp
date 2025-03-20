#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[10][10];
vector<pair<int, int>> cctv_pos; // cctv좌표
int ans = 0x7fffffff;
int dx[4] = {1, 0, -1, 0}; // 우 상 좌 하
int dy[4] = {0, 1, 0, -1};

// 사각지대에 벽도 포함
// 실질적으로 cctv움직이는함수
// void cctv_move()
// {
//     // cctv종류별로 다르게움직여야하는데 어떻게 구현할것인가

//     int tmp[10][10];
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             tmp[i][j] = board[i][j];
//         }
//     }

//     for (int i = 0; i < cctv.size(); i++)
//     {
//         if (cctv[i] == 1)
//         {
//             // 4방향

//             for (int dist = 1; dist <= 8; dist++)
//             {
//                 int nx = dist * dx[i];
//                 int ny = dist * dy[i];
//                 if (nx < 0 || nx >= n || ny < 0 || ny >= m)
//                     break; // 범위 넘어가면 종료
//                 if (board[nx][ny] == 6)
//                     break; // 벽만나면 종료
//                 visit[nx][ny] = '#'
//             }
//         }
//         cctv_pos[i].first
//     }
// }

// 회전 --> HOW? 90도로
void circ(int x, int y, int dir)
{
    //???
    dir %= 4;
    while (1)
    {
        x += dx[dir];
        y += dy[dir];
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == 6)
            return;
        if (board[x][y] != 0)
            continue;
        board[x][y] = -1;
    }
}

// 백트래킹
void dfs(int depth)
{

    if (depth == cctv_pos.size())
    {
        int temp_ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 0)
                {
                    temp_ans++;
                }
            }
        }
        ans = min(ans, temp_ans);
        return;
    }

    int x = cctv_pos[depth].first;
    int y = cctv_pos[depth].second;

    int backup[10][10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            backup[i][j] = board[i][j];
        }
    }

    for (int dir = 0; dir < 4; dir++)
    { // 일단 다 4번 회전
        if (board[x][y] == 1)
        {
            circ(x, y, dir);
        }
        if (board[x][y] == 2)
        {
            circ(x, y, dir);
            circ(x, y, dir + 2);
        }
        if (board[x][y] == 3)
        {
            circ(x, y, dir);
            circ(x, y, dir + 1);
        }
        if (board[x][y] == 4)
        {
            circ(x, y, dir);
            circ(x, y, dir + 1);
            circ(x, y, dir + 2);
        }
        if (board[x][y] == 5)
        {
            circ(x, y, dir);
            circ(x, y, dir + 1);
            circ(x, y, dir + 2);
            circ(x, y, dir + 3);
        }

        //위에서 바꿔놓고 다음dfs돌리고 원상복구시키기
        dfs(depth + 1); // 다음 cctv로

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board[i][j] = backup[i][j];
            }
        }
    }
}

int main(void)
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            // 0은빈칸 6은벽 1~5는 cctv
            if (board[i][j] >= 1 && board[i][j] <= 5)
            {
                cctv_pos.push_back({i, j});
            }
        }
    }

    dfs(0);
    cout << ans;
    return 0;
}