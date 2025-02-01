#include <bits/stdc++.h>
using namespace std;

int n;
int maze[1005][1005];
char input[1005][1005];

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};
int ans[1005][1005];

// 칸과 인접해 있는 여덟 개의 칸들에 들어 있는 지뢰의 총 개수

int main(void)
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> input[i][j];
            if (input[i][j] != '.')
            {
                ans[i][j] = -1; //지뢰
            }
            else{
                ans[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ans[i][j] == -1) // 지뢰라면
            {
                for (int k = 0; k < 8; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || ans[nx][ny] == -1)
                        continue;
                    ans[nx][ny] += input[i][j] - '0';
                }
            }
        }
    }

    // 10넘는것들은 M으로 바꾸기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ans[i][j] >= 10)
            {
                cout << 'M';
            }
            else if(ans[i][j] == -1){
                cout << '*';
            }
            else{
                cout << ans[i][j];
            }
        }
        cout << '\n';
    }

    return 0;
}