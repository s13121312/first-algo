#include <iostream>
using namespace std;

int n;
int arr[505][505];
int dp[505][505];
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
}
int ans = 0;

//x,y에서 시작했을때 밟고 갈 수 있는 최대 칸 수
int pro(int x, int y, int move_cnt){
    if(dp[x][y]){
        return dp[x][y];
    }

    int maxcnt = 1;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || nx>=n || ny<0 || ny>=n)continue;
        if(dp[nx][ny])continue;
        if(arr[nx][ny] <= arr[x][y])continue;

        maxcnt = max(maxcnt, move_cnt);
        pro(nx, ny, move_cnt++);
    }
    
    dp[x][y] = move_cnt;
    cout << maxcnt;
    return move_cnt;

}

void init(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = 1;
        }
    }
}

void pro2(){
    init();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmp =1;
            for(int d=0;d<4;d++){
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
                if(arr[nx][ny] <= arr[i][j])continue;
                dp[nx][ny] = max(dp[nx][ny], dp[i][j] + 1);
                //cout << dp[nx][ny];
            }
        }
    }
}

int main() {
    // Please write your code here.
    input();
    pro2();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans = max(ans, dp[i][j]);
            //cout << ans << '\n';
        }
    }
    cout << ans;

    return 0;
}