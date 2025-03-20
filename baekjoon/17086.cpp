#include <bits/stdc++.h>
using namespace std;

int space[55][55];
int isused[55][55];
queue<pair<int, int>> q;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int n, m;

void init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			isused[i][j] = -1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> space[i][j];
        }
    }

    //TODO isused중간에 초기화해줘야함
    vector<int> arr;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (space[i][j] == 0)
            {
                int a= 1e9;
                init();
                q.push({i, j});
                isused[i][j] = 0;

                while (!q.empty())
                {
                    auto cur = q.front();
                    q.pop();

                    for(int dir=0;dir<8;dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx<0 || nx>=n || ny <0 || ny>=m) continue;
                        if(isused[nx][ny] != -1)continue;
                        
                        if(space[nx][ny]==1){
                            isused[nx][ny] = isused[cur.first][cur.second]+1;
                            a = min(isused[nx][ny],a);
                            
                        }
                        else{
                            isused[nx][ny] = isused[cur.first][cur.second]+1;
                            q.push(make_pair(nx,ny));
                        }
                        
                    }

                }
                arr.push_back(a);
            }
        }
    }

    sort(arr.rbegin(),arr.rend()); //내림차순 정렬
    cout << arr[0];
    return 0;
}