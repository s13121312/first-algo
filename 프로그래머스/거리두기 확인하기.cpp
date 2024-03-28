//https://winterflower.tistory.com/270

#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
vector<string> p;

bool bfs(int x, int y)
{
    // P인 x,y가 들어온상태

    bool visit[5][5] = {false};
    queue<pair<pair<int,int>,int>> q;
    visit[x][y]=true;
    q.push({{x,y},0}); //출발점
    while (!q.empty())
    {
        int cur_x = q.front().first.first;
        int cur_y = q.front().first.second; //cur 처리
        int cnt = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if(nx<0 || nx>4 || ny<0 || ny>4) continue;
            if(visit[nx][ny] || p[nx][ny] == 'X') continue;
            if(p[nx][ny]=='P'){
                if(cnt + 1 <= 2){
                    return false;
                }
            }
            visit[nx][ny] = true;
            q.push({{nx,ny},cnt+1});
        }
    }
    return true;
    
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for (int i = 0; i < 5; i++)
    {
        p = places[i];
        bool result = true;
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (places[i][j][k] == 'P')
                {
                    if (!bfs(j, k))
                    {
                        result = false;
                        break;
                    }
                }
                if(!result) break;
            }
        }
        if (result)
        {
            answer.push_back(1);
        }
        else
        {
            answer.push_back(0);
        }
    }

    return answer;
}