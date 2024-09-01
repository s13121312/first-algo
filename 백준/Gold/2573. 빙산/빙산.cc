#include<bits/stdc++.h>
using namespace std;

int n ,m;
int arr[305][305];
int ans = 0;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
void input(){
    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
}

void chk(){

    
    vector<pair<pair<int,int>,int>> v;


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]>0){
                int cnt = 0;
                for(int d=0;d<4;d++){
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if(nx<0 || nx>=n || ny<0 || ny>=m)continue;
                    if(arr[nx][ny] == 0)cnt++;
                }
                if(cnt>0)v.push_back({{i,j},cnt});
                
            }
        }
    }

    for(auto cur : v){
        int x = cur.first.first;
        int y = cur.first.second;
        int cnt = cur.second;
        arr[x][y] = arr[x][y] - cnt;
        if(arr[x][y] < 0)arr[x][y] = 0;
    }
    ans++; //몇년이 지났는지

}

//두 덩어리 이상으로 분리되는지
bool bfs(){
    bool visit[305][305] = {false};
    int cnt = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] > 0 && !visit[i][j]){
                cnt++;
                if(cnt>=2)return true;
                queue<pair<int, int>> q;
                q.push({i,j});
                visit[i][j] = true;
                
                while (!q.empty())
                {
                    auto cur = q.front(); q.pop();
                    for(int d = 0; d<4;d++){
                        int nx = cur.first + dx[d];
                        int ny = cur.second + dy[d];
                        if(nx<0 || nx>=n || ny<0 || ny>=m || visit[nx][ny] || arr[nx][ny] == 0)continue;
                        q.push({nx,ny});
                        visit[nx][ny] = true;   
                    }
                }
            
            }
            
        }
    }
    
    return false;
}

void pro(){
    while (true)
    {
        if(bfs())break;
        chk();
        
        bool all_melted = true;
        for(int i=0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(arr[i][j] >0){
                    all_melted= false;
                    break;
                }
            }
            if(!all_melted)break;
        }

        if(all_melted){
            ans =0; 
            break;
        }
    }
    
    cout << ans;
}

int main(){

    input();
    pro();

    return 0;
}