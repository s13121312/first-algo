#include<bits/stdc++.h>
using namespace std;
int n,l,r;
int arr[55][55];
bool vis[55][55];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

/*
    1h
    처음에 isCombined[][] 이차원 배열로 연합이 되는 좌표들을 true로 저장해서 한번에 bfs로 돌리는 방법으로 했는데 테스트 케이스가 다 맞아서 
    제출했는데 바로 틀려버렸음
    반례를 찾아보다가 출력값들이 이상하단걸 깨달음. 위 방법으로는 
    10 100 50 50 
    50 50 50 50
    50 50 50 50
    50 50 100 50

    (0,0), (1,0), (0,1), (0,2)가 한번에 처리되어서
    맞는 방법으로 하면 
    (0,0), (1,0)만 같이 처리가 되어야하는것이 단추가 잘못 끼워지게 된다.

    <반례>
    9 1 2
    1 2 3 4 5 6 7 8 9
    4 5 6 7 8 9 1 2 3
    3 4 5 6 7 8 9 1 2
    2 3 4 1 2 3 4 5 6
    3 4 5 8 9 1 2 3 4
    5 5 5 5 5 1 2 4 4
    1 1 1 1 2 3 4 5 6
    9 8 7 6 5 4 3 3 3
    2 3 4 1 2 3 4 5 6
    정답: 13
    */

bool bfs(int x, int y, vector<pair<int, int>>& pos) {
    int cnt = 0, sum = 0;
    cnt = 1;
    sum = arr[x][y];
    queue<pair<int, int> > q;
    q.push({x, y});
    vis[x][y] = true;
    pos.push_back({x,y});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        
        for(int i=0;i<4;i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=n || vis[nx][ny])continue;
            int diff =abs(arr[cur.first][cur.second] - arr[nx][ny]);
            if(diff >= l && diff <= r){
                q.push({nx, ny});
                vis[nx][ny] = true;
                cnt++;
                sum += arr[nx][ny];
                pos.push_back({nx, ny});      
            }      
        }
    }
    
    if(cnt>1){
        int avg = sum/cnt;
        for(auto p : pos) {
            arr[p.first][p.second] = avg;
        }
        return true;
    }
    

    return false;
}

bool processingcombine() {
    bool moved = false;
    for(int i=0;i<n;i++) {
        fill(vis[i], vis[i]+n, false);
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(vis[i][j])continue;
            int cnt = 0;
            int sum = 0;
            vector<pair<int, int>> pos;
            if(bfs(i,j, pos)) {
                moved = true;
            }
        }
    }

    return moved;
}

void print() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

}
int main() {

    cin >> n >> l >>r;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }
    int cnt = 0;

    while(processingcombine()) {
        //print();
        cnt++;
    }


    cout << cnt;
    return 0;
}