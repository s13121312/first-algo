#include <bits/stdc++.h>

using namespace std;
int n;
int dist[100][100][2]; 
//현재 상태가 가로로 누워있을떄
//현재 상태가 세로일때
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool safe(int x, int y) {
    return y >= 0 && x >= 0 && y < n && x < n;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    n = board.size();
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            dist[i][j][0] = dist[i][j][1] = -1;
        }
    }
    
    queue<tuple<int, int, int>> q; //로봇의 축 좌표(더 , [가로(0),세로(1)]
    q.push({0, 0, 0});   //(0,0) (0,1), 가로
    dist[0][0][0] = 0;
    
    while(!q.empty()) {
        int x, y, dir;
        tie(x,y, dir) = q.front();   // == auto [y, x, dir] = q.front();
        int x2 = x + (dir==1), y2 = y + (dir==0); //가로(0), 세로(1)
        if((x==n-1 && y==n-1) || (x2==n-1 && y2==n-1)) {
            return dist[x][y][dir];
        }
        q.pop();
        int nextdist = dist[x][y][dir]+1;
        
        //그냥 평행이동일때
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            int nx2 = x2 + dx[i];
            int ny2 = y2 + dy[i];
            if(!safe(nx,ny) || !safe(nx2, ny2))continue;
            if(board[nx][ny] || board[nx2][ny2])continue;
            
            if(dist[nx][ny][dir] == -1 || dist[nx][ny][dir] > nextdist) { //방문안했거나 원래 놓은값보다 작으면 최소값으로 갱신
                dist[nx][ny][dir] = nextdist;
                q.push({nx,ny,dir});
            }
            
        }
        
        //회전
        if(dir == 0) {  //가로 -> 세로
            for(int up = -1;up <= 1;up += 2) {
                int nx = x + up;
                ////회전할떄 벽을 마주치지않고 범위를 넘어가지않는 거 선택
                if(safe(nx,y) && safe(nx, y+1) && board[nx][y] == 0 && board[nx][y+1] == 0) {
                      for(int ny : {y, y+1}) {
                          if(dist[min(x, nx)][ny][1] == -1 || dist[min(x,nx)][ny][1] > nextdist) { //축(기준)이 더 작은걸로 해야됨                  
                              dist[min(x,nx)][ny][1] = nextdist;
                              q.push({min(x,nx), ny, 1});
                          }
                      }
                }
            }
        } else { // 세로 -> 가로
            for(int lr = -1;lr <= 1;lr += 2) {
                int ny = y + lr;
                ////회전할떄 벽을 마주치지않고 범위를 넘어가지않는 거 선택
                if(safe(x, ny) && safe(x+1, ny) && board[x][ny] == 0 && board[x+1][ny] == 0) {
                      for(int nx : {x, x+1}) {
                          if(dist[nx][min(y,ny)][0] == -1 || dist[nx][min(y,ny)][0] > nextdist) { //축(기준)이 더 작은걸로 해야됨                  
                              dist[nx][min(y,ny)][0] = nextdist;
                              q.push({nx, min(y,ny), 0});
                          }
                      }
                }
            }
        } 
        
        
    }
    
    return 0;
}