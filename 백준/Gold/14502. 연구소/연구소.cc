#include<bits/stdc++.h>
using namespace std;
int n, m;
int arr[10][10];
bool vis[10][10]; //벽 세워진적있던곳 체크
int ans = 0; //안전 영역 최대 크기
vector<pair<int,int> > builtwall; //벽으로 지정된 좌표 저장
int dx[] = {1,0,-1, 0};
int dy[] = {0, 1, 0, -1};
int ansarr[10][10];  //디버깅용 정답 arr



void input() {
    cin >> n >>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> arr[i][j];
        }
    }
}

//바이러스 퍼뜨리기
int bfs(int tmp[10][10]) {

    bool chk[10][10];
    for(int i=0;i<n;i++) fill(chk[i], chk[i]+m, false);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(tmp[i][j] == 2) {
                queue<pair<int, int> > q;
                q.push({i, j});
                chk[i][j] = true;

                while(!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for(int d=0;d<4;d++) {
                        int nx = cur.first + dx[d];
                        int ny = cur.second + dy[d];
                        if(nx<0 || nx>=n || ny<0 || ny>=m)continue;
                        if(chk[nx][ny] || tmp[nx][ny] == 1)continue;

                        tmp[nx][ny] = 2;
                        q.push({nx,ny});
                        chk[nx][ny] = true;
                    }
                }
            }
        }
    }
    
    
    int con = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(tmp[i][j] == 0)con++;
        }
    }

    return con;
}

//벽 3개 세우기
void buildwall(int idx, int depth) {

    int x = idx/m, y =idx%m;  //
    
    

    if(depth == 3) {
        //tmp로 벽생긴거 + 원래 arr붙이기
        int tmp[10][10];
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                tmp[i][j] = arr[i][j];
            }
        }
        //builtwall좌표로 벽 만들기
        tmp[builtwall[0].first][builtwall[0].second] = 1;
        tmp[builtwall[1].first][builtwall[1].second] = 1;
        tmp[builtwall[2].first][builtwall[2].second] = 1;
        
        // ans = max(ans, bfs(tmp));
        int tm =bfs(tmp);
        if(ans < tm) {

            ans = tm;
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    ansarr[i][j] = tmp[i][j];
                }
            }
        }
        return;
    }

    if(idx >= n*m)return;
    
    if(arr[x][y] == 0) {
        builtwall.push_back({x, y});
        buildwall(idx+1, depth+1);
        builtwall.pop_back();
    } 
    //// 안 세우고 넘어가는 경우
    buildwall(idx+1, depth);
    

}


int main() {

    input();
    buildwall(0, 0);
    cout << ans << '\n';
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cout << ansarr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
}