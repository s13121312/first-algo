#include <bits/stdc++.h>
using namespace std;

int arr[7][7];
int tmp[7][7];
int k, m;
int wallNumber[305];
void processing();
bool gainThing();
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
int waillIndex = 0;
void printTmp(int a[7][7]);

void input() {
    cin >> k >> m;
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            cin>> arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        cin >> wallNumber[i];
    }
}

void init() {
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            tmp[i][j] = arr[i][j];
        }
    }
}

//유물 1차획득 가치, 회전 각도, 중심 좌표(행,열)
bool cmp(pair<pair<int, int>, pair<int,int>> a, pair<pair<int, int>, pair<int,int>> b) {
    if(a.first.first == b.first.first){
        if(a.first.second == b.first.second){
            if(a.second.second == b.second.second){
                return a.second.first < b.second.first;
            }
            return a.second.second < b.second.second;
        }
        return a.first.second < b.first.second;
    }
    return a.first.first > b.first.first;
}

//3*3  90도회전    //앞 단원 참고하기 회전 tip 
void rotate(int x, int y, int d) {
    init();
    if(d==0){
        tmp[x-1][y-1] = arr[x+1][y-1];
        tmp[x-1][y] = arr[x][y-1];
        tmp[x-1][y+1] = arr[x-1][y-1];

        tmp[x][y+1] = arr[x-1][y];
        tmp[x+1][y+1] = arr[x-1][y+1];

        tmp[x+1][y] = arr[x][y+1];
        tmp[x+1][y-1] = arr[x+1][y+1];
        
        tmp[x][y-1] = arr[x+1][y]; 
    
    } else if(d == 1) {
        tmp[x-1][y-1] = arr[x+1][y+1];
        tmp[x-1][y] = arr[x+1][y];
        tmp[x-1][y+1] = arr[x+1][y-1];
        tmp[x][y+1] = arr[x][y-1];
        tmp[x+1][y+1] = arr[x-1][y-1];
        tmp[x+1][y] = arr[x-1][y];
        tmp[x+1][y-1] = arr[x-1][y+1];
        tmp[x][y-1] = arr[x][y+1]; 
    } else if(d == 2) {
        tmp[x-1][y-1] = arr[x-1][y+1];
        tmp[x][y-1] = arr[x-1][y];
        tmp[x+1][y-1] = arr[x-1][y-1];
        tmp[x-1][y] = arr[x][y+1];
        tmp[x-1][y+1] = arr[x+1][y+1];
        tmp[x][y+1] = arr[x+1][y];
        tmp[x+1][y+1] = arr[x+1][y-1];
        tmp[x+1][y] = arr[x][y-1]; 
    }
}

int calcFirstGain() {
    bool visit[7][7] = {false, };  //vector<vector<bool>> visited(5, vector<bool> (5,false))
    queue<pair<int, int>> q;
    vector<pair<int, int>> pos;  //저장할 좌표들

    int g = 0;
    
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            if(visit[i][j])continue;
            pos.clear();
            q.push({i,j});
            visit[i][j] = true;
            pos.push_back({i,j});
            int t = 1;
            while(!q.empty()) {
                
                auto cur = q.front();
                q.pop();
                for(int i=0;i<4;i++) {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];
                    if(nx<0 || nx>=5 || ny<0 || ny>=5 || visit[nx][ny])continue;
                    if(tmp[cur.first][cur.second] == tmp[nx][ny]){
                        visit[nx][ny] = true;
                        q.push({nx,ny});
                        pos.push_back({nx, ny});
                        t++;
                    }
                }
            }
            if(t >= 3){
                g += t;
                for(auto x: pos) {
                    tmp[x.first][x.second] = 0;
                }
            }
        }
    }
    return g;
}

int resD, resX, resY;
void processing() {
    vector<pair<pair<int, int>, pair<int,int>>> method; //유물 1차획득 가치, 회전 각도, 중심 좌표(행,열)

    for(int i=1;i<=3;i++) {
        for(int j=1;j<=3;j++) {
            for(int d=0;d<3;d++){
                for(int z=0;z<=d;z++){
                    rotate(i,j,d);
                    int g = calcFirstGain();
                    method.push_back({{g, d}, {i,j}});
                }
            }
        }
    }
    sort(method.begin(),method.end(),cmp);
    resD = method[0].first.second, resX = method[0].second.first, resY = method[0].second.second;    //각도, 중심좌표
}


void fillWithWallElements() {
    
    for(int j=0;j<5;j++){
        for(int i=4;i>=0;i--){
            if(tmp[i][j] == 0) tmp[i][j] = wallNumber[waillIndex++];
            if(waillIndex>=m)return;
        }
    }
}

void pro() {
    while(k--) {
                
        processing();
        //위에서 얻은 각도,중심으로 회전
        //cout << resX << ' ' << resY << ' '<< resD<< ' ';
        rotate(resX, resY, resD);

        int gain = 0;
        bool chk = false;
        while(1) {
            int cg = calcFirstGain();
            if(cg <= 0) break;
            else chk = true;
            
            gain += cg;  //얻은 유물 가치 총합
            //cout << "채우기 전: '\n'";
            //printTmp(tmp);
            
            fillWithWallElements();
            //cout << "채우기 후: '\n'";
            //printTmp(tmp);
        }
        
        //tmp랑 arr동기화
        for(int i=0;i<5;i++) {
            for(int j=0;j<5;j++) {
                arr[i][j] = tmp[i][j];
            }
        }
        
        if(gain != 0)cout << gain << ' ';
        if(!chk){
            break; //한번이라도 얻은 유물이 있으면 pass
        }
    }
}
void printTmp(int a[7][7]) {
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    // Please write your code here.
    input();
    pro();
    // rotate(2,2,0);
    // printTmp(tmp);
    // cout << calcFirstGain() << '\n';
    // printTmp(tmp);
    return 0;
}