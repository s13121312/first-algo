#include<bits/stdc++.h>
using namespace std;
int r, c, k;
char arr[7][7];
bool vis[7][7] = {false,};
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int answer = 0;

void dfs(int x, int y, int len) {
    
    if(x == 0 && y == c-1) {
        if(len == k)answer++;
        return;
    }
    

    for(int i=0;i<4;i++) {
        int cx = x+dx[i], cy = y+dy[i];
        if((cx>=0 && cx<r && cy>=0 && cy<c) && !vis[cx][cy] && arr[cx][cy] != 'T'){
            vis[cx][cy] = true;
            dfs(cx, cy, len + 1);
            vis[cx][cy] = false;
        }
        
    }
}

int main() {

    cin >> r >> c >> k;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cin >> arr[i][j];
        }
    }

    vis[r-1][0] = true;
    dfs(r-1, 0, 1);
    cout << answer;

    return 0;
}