#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
int n, r, c;
int arr[5][5];
int dir[5][5];
int ans = 0;

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> dir[i][j];
            dir[i][j]--;
        }
    }
    cin >> r >> c;
    r--;c--;

}

void backtracking(int cur, int x, int y){
    int d = dir[x][y];

    for(int j=1;j<n;j++){
        int nx = x + dx[d]*j;
        int ny = y + dy[d]*j;
        if(nx < 0 || nx >= n || ny<0 || ny>=n || arr[nx][ny]<= arr[x][y])continue;
        //cout << "nx: " << nx << ", ny: " << ny << '\n';
        cur = cur+1;
        ans = max(ans, cur);
        backtracking(cur, nx, ny);
        cur--;
    }
        
}

void pro(){
    
    backtracking(0, r, c);
    cout << ans;
}

int main() {
    // Please write your code here.
    input();
    pro();

    return 0;
}