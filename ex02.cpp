#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int>> land;
int dx[] = {1,0,-1,0}; int dy[] = {0,1,0,-1};
int amount[505];

int depth = 1;

void print() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << land[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void bfs2() {
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int> > q;
    int tmp = 0;
    
            q.push({i,j});
            land[i][j] = depth;
            vis[i][j] = true;
            
            
            while(!q.empty()) {
                auto cur = q.front();
                q.pop();
                tmp++;
                for(int d=0;d<4;d++) {
                    int nx = cur.first + dx[d];
                    int ny = cur.second + dy[d];
                    if(nx<0 || nx>=n || ny<0 || ny>=m || vis[nx][ny] || land[nx][ny] == 0)continue;
                    land[nx][ny] = depth;
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                    
                }
            }
            
            amount[depth++] = tmp;
        
    
}


int solution(vector<vector<int>> _land) {
    int ans = 0;
    n = _land.size();
    m = _land[0].size();
    land = _land;
    
   
    bfs2();
    print();
    
    for(int i=0;i<n;i++) {
        int t = 0;
        set<int> s;
        for(int j=0;j<m;j++) {
            s.insert(land[i][j]);
            t += amount[land[i][j]];
        }
        
        ans = max(ans, t);
    }
    
    return ans;
}