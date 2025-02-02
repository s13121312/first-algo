#include <bits/stdc++.h>
using namespace std;

int n, l ,r;
int arr[55][55];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void input(){
    cin >> n >> l >> r;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
}
int tmp[55][55];

void initTmp(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tmp[i][j] = arr[i][j];
        }
    }
}

bool bfs(){
    vector<vector<bool>> visit(n, vector<bool>(n,false)); 
    //bool visit[55][55] = {false, };
    initTmp();
    bool finalChk = false;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(visit[i][j])continue;
            visit[i][j] = true;
            queue<pair<int, int>> q;
            q.push({i, j});
            vector<pair<int, int>> selected;
            int sizeEggBottle = 1;
            selected.push_back({i, j});
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];
                    if(nx<0 || nx>=n || ny<0 || ny>=n || visit[nx][ny])continue;
                    
                    int absEggs = abs(arr[nx][ny] - arr[cur.first][cur.second]);
                    if(absEggs >= l && absEggs <= r){
                        selected.push_back({nx, ny});
                        visit[nx][ny] = true;
                        q.push({nx, ny});
                        sizeEggBottle++;
                    }
                }
            }
            if(sizeEggBottle >= 2)finalChk = true; //이동하는 계란이 있다면 true리턴

            int sumOfEgg = 0;
            for(auto x : selected) {
                sumOfEgg += arr[x.first][x.second];
            }

            int initEgg = sumOfEgg/sizeEggBottle;

            // for(auto x: selected) {
            //     cout << x.first << ' ' << x.second << '\n';
            // }
            // cout << '\n';

            for(auto pos: selected){
                tmp[pos.first][pos.second] = initEgg;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = tmp[i][j];
        }
    }
    
    if(finalChk)return true;
    else return false;
}

void printArr(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
void pro(){

    int ans = 0;
    while(1){
        if(bfs()){
            //printArr();
            ans++;
        } else {
            break;
        }
    }
    cout << ans;
}

int main() {
    // Please write your code here.
    input();
    pro();

    return 0;
}

//30 50 10 30 45 (165) 5

/*
분리 되는지를 체크를 하는데 bfs돌면서 둘의 차이가 l이상R이하이면은 selected에추가

*/