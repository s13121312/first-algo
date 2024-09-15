#include<bits/stdc++.h>
using namespace std;

int n;
int arr[1005][1005];
bool vis[1005][1005];
int ans = 0;

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0, 1};

int main(){

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    queue<pair<int, int>> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 1 && !vis[i][j]){
                
                q.push({i,j});
                vis[i][j] = true;
                ans++;
                while (!q.empty())
                {
                    auto cur = q.front();
                    q.pop();
                    
                    for(int d=0;d<4;d++){
                        int nx = cur.first + dx[d];
                        int ny = cur.second + dy[d];
                        if(nx<0 || nx>=n || ny<0 || ny>=n)continue;
                        if(vis[nx][ny] || arr[nx][ny] == 0)continue;
                        
                        q.push({nx,ny});
                        vis[nx][ny] = true;
                    }
                }
            }
        }
    }


    cout << ans;

    return 0;
}