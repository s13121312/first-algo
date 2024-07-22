#include<bits/stdc++.h>
using namespace std;

int n;
int board[5][5];
int dx[2] = {1, 0}; //아래, 오른쪽
int dy[2] = {0, 1};
bool vis[5][5];

int main(void){

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }

    queue<pair<int,int>> q;
    q.push({0,0});

    while (!q.empty())
    {
        auto cur = q.front();q.pop();   
        for(int i=0;i<2;i++){ //오른쪽 아래쪽
            int nx = cur.first + dx[i]*board[cur.first][cur.second]; //써져있는만큼 이동
            int ny = cur.second + dy[i]*board[cur.first][cur.second];
            if(nx<0 || nx>=n || ny<0 || ny>=n)continue;
            if(vis[nx][ny])continue;
            if(nx == n-1 && ny == n-1){
                cout << "HaruHaru";
                return 0;
            }
            vis[nx][ny] = true;
            q.push({nx,ny});
        }
    }
    
    cout << "Hing";

    return 0;
}