#include<vector>
#include<string.h>
#include<queue>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    
    int isused[maps.size()+5][maps[0].size()+5];

    for(int i=0;i<maps.size();i++){
        memset(isused[i],-1,sizeof(isused[i]));
    }
    queue<pair<int,int>> q;
    isused[0][0]=1;
    q.push({0,0});

    while (!q.empty())
    {
        auto cur = q.front();q.pop();

        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx<0 || nx>=maps.size() || ny<0 || ny>=maps[0].size()) continue;
            if(isused[nx][ny]>=1 || maps[nx][ny]==0)continue;
            isused[nx][ny] = isused[cur.first][cur.second]+1;
            q.push({nx,ny});
        }
    }
    
    answer = isused[maps.size()-1][maps[0].size()-1];
 
    return answer;
}