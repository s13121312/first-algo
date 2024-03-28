//로직은맞느거같은데 답이안나옴 
#include <bits/stdc++.h>
using namespace std;

char arr[7][7];
int ans = 0;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool isused[7][7];

bool visit[7][7];

bool morethanFour()
{
    int idasom = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (isused[i][j])
            {
                if (arr[i][j] == 'S')
                {
                    idasom++;
                }
            }
        }
    }
    if(idasom >= 4)return true;
    else{
        return false;
    }
}

//인접하냐 아니냐 bfs돌면서 체크
bool Adj(){

    queue<pair<int, int>> q;


    bool first = true; //첫번째놈만넣음
    for(int i=0;i<25;i++){
        int xx = i/5;
        int yy = i%5;
        if(isused[xx][yy]){
            if(first){
                first = false;
                q.push({xx,yy});
                visit[xx][yy] = true;
            }
        }
    }

    int stu = 1; //첫 학생이 큐에 들어감
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if(stu == 7){
            return true;
        }
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<0 || nx>=5 || ny<0 || ny >=5)continue;
            if(visit[nx][ny] || !isused[nx][ny])continue;
            q.push({nx,ny});
            visit[nx][ny] = true;
            stu++;
        }

    }
    

}

void dfs(int depth, int st)
{
    if (depth == 7)
    {
        if(morethanFour()){
            if(Adj()){
                ans++;
            }
        }
        return;
    }

    // 7명 고르기
    for(int i=st;i<25;i++){
        int xx = i/5;
        int yy = i%5;
        if(isused[xx][yy])continue;
        isused[xx][yy] = true;
        dfs(depth + 1, i);
        isused[xx][yy] = false;
    }
}

int main(void)
{

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }
    dfs(0,0);
    cout << ans;
    return 0;
}