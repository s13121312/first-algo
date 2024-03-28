#include <bits/stdc++.h>
using namespace std;

int n, m; // n은 세로 m은 가로

int board[10][10];

int dx[4] = {1, 0, -1, 0}; // 0은 오른쪽, 1은 위, 2는 왼쪽 3은 아래
int dy[4] = {0, 1, 0, -1};

int answer = 64; // 최대 64개이므로 이렇게 둠
vector<pair<int, int>> cctv_pos;
// 0은빈칸 6은벽 1~5는 cctv

bool oob(int x, int y)
{ // out of bound
    return x < 0 || x >= n || y < 0 || y >= m;
}

void check(int x, int y, int dir)//실질적으로 움직이게하는함수
{
    dir %= 4; // dir이 3보다 큰 경우를 위해
    while (1)
    {
        x += dx[dir];
        y += dy[dir];
        if (oob(x, y) || board[x][y] == 6) return; //함수끝내야됨 벽만나거나 범위 넘으면
        if(board[x][y] != 0)continue;//0이아니면 cctv란건데 얘는 건너뛰기
        board[x][y] = '#';
    }
}

// idx 번째 cctv를 회전
void solve(int idx)
{
    int cctv_cnt = cctv_pos.size();
    if (idx == cctv_cnt)
    {
        int temp_answer = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 0)
                {
                    temp_answer++;
                }
            }
        }
        answer = min(answer, temp_answer);
        return;
    }

    int x = cctv_pos[idx].first;
    int y = cctv_pos[idx].second;
    int backup[10][10];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            backup[i][j] = board[i][j];
        }
    }

    for (int dir = 0; dir < 4; dir++) // 4번회전
    {
        if (board[x][y] == 1)
        {
            check(x, y, dir); //dir=0일때 right
        }
        else if (board[x][y] == 2)
        {
            check(x,y,dir); //서로 반대방향인거
            check(x,y,dir+2);//dir=0일때 right,left
        }
        if (board[x][y] == 3)
        {
            check(x,y,dir);//dir=0일때 right,up
            check(x,y,dir+1);
        }
        if (board[x][y] == 4)
        {
            check(x,y,dir);
            check(x,y,dir+1);
            check(x,y,dir+2);
        }
        if (board[x][y] == 5)
        {
            check(x,y,dir);
            check(x,y,dir+1);
            check(x,y,dir+2);
            check(x,y,dir+3);
        }
        solve(idx + 1);
        for (int i = 0; i < n; i++) // 상위단계갔다가 이전단계로 돌아올때 복구시켜줌
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
            if (board[i][j] >= 1 && board[i][j] <= 5) // cctv 넣기
            {
                cctv_pos.push_back({i, j});
            }
        }
    }
    solve(0);

    cout << answer;

    return 0;
}