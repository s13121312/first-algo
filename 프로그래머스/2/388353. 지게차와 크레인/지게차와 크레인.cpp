#include<bits/stdc++.h>

using namespace std;
int n, m;
char next_arr[55][55];
vector<string> arr;
int dx[] = {1,0,-1,0}; int dy[] = {0,-1,0,1};
void syncArr();


void externalfindStr(char s) {
    
    queue<pair<int,int>> q;
    vector<vector<bool>> cleanArea(55, vector<bool>(55, false)); //0인 부분이면서 바깥에있는 부분
    q.push({0,0});
    cleanArea[0][0] = true;
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int d=0;d<4;d++) {
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];
            if(nx<0 || nx>n+1 || ny<0 || ny>m+1 || cleanArea[nx][ny])continue;
            if(next_arr[nx][ny] == '0'){
                q.push({nx,ny});
                cleanArea[nx][ny] = true;
            }
        }
    }
    
    
    vector<pair<int,int> > pos; //지워야할 위치
    //밖에서 접근할 수 있는걸 
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(next_arr[i][j] == '0')continue;
            int canAccess=0;
            for(int d=0;d<4;d++){
                int nx= i + dx[d];
                int ny = j + dy[d];
                if(next_arr[nx][ny] == '0' && cleanArea[nx][ny]){
                    canAccess++;
                }
            }
            if(canAccess>=1){
                if(next_arr[i][j] == s)pos.push_back({i, j});
            }
        }
    }
    for(auto x: pos) {
        next_arr[x.first][x.second] = '0';
    }    
    
    syncArr();
    
}

void findStr(char s) {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(next_arr[i][j] == s)next_arr[i][j] = '0';
        }
    }
    syncArr();
}

int chkRemain() {
    int r = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if('A' <= next_arr[i][j] && next_arr[i][j] <= 'Z') r++;
        }
    }
    return r;
}

void init() {
    for(int i=0;i<=n+1;i++) {
        for(int j=0;j<=m+1;j++) {
            next_arr[i][j] = '0';
        }
    }   
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            next_arr[i+1][j+1] = arr[i][j];
        }
    }    

}

void syncArr() {
    //next_Arr랑 arr랑 바뀐부분 맞춰주기
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            arr[i-1][j-1] = next_arr[i][j];
        }
    }
}

void print() {
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            cout << next_arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
int solution(vector<string> _storage, vector<string> requests) {
    int answer = 0;
    arr = _storage;
    n = arr.size();
    m = arr[0].size();
    init();
    
    for(string input : requests) {
        if(input.size() == 1) {
            //지게차로 외부에서만 접근 가능 
            externalfindStr(input[0]);            
        } else if(input.size() == 2) {
            //크레인으로 input[0]의 문자는 다 뽑아내기
            findStr(input[0]);
            
        }
        //print();
    }
    
    answer = chkRemain();
    print(); //바뀌질 않았음.
    
    return answer;
}