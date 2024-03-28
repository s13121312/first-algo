//다시 풀어봐야겠구만
#include <bits/stdc++.h>
using namespace std;

int r, c, n;
char arr[205][205];
bool visit[205][205];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{

    cin >> r >> c >> n;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    // n초까지의 과정
    // n이 1일때는 그대로

    if (n % 2 == 0)
    {
        // 다 O로
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << 'O';   
            }
            cout << '\n';
        }
        return 0;
    }
    
    if (n == 1)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << arr[i][j];
            }
            cout << '\n';
        }
        return 0;
    }

    int now =1;
    queue<pair<int,int>> q;
    while (now<n)
    {
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(arr[i][j] == 'O'){
                    q.push({i,j});
                }
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                arr[i][j] = 'O';                
            }
        }

        while (!q.empty())
        {
            auto cur = q.front(); 
            q.pop();
            arr[cur.first][cur.second] = '.';
            for(int i=0;i<4;i++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c)continue;
                arr[nx][ny] = '.';
            }
        }
    
        now += 2;//짝수 처리는 앞에서 처리했으니까 넘김
    }

    //정답 출력
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    }
    return 0;
}