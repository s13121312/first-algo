#include <iostream>
using namespace std;

int dx[] = {1,0};
int dy[] = {0,1};
int visited[105][105];
int arr[105][105];
int n, m;

void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
}

//1은길 0은뱀 
bool chk = false;

void pro(int x, int y){

    if(x == n-1 && y == m-1){
        chk = true;
    }
    for(int i=0;i<2;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || nx>=n || ny<0 || ny>=m || visited[nx][ny] || arr[nx][ny]==0)continue;
        visited[nx][ny] = true;
        pro(nx, ny);
    }
}

int main() {
    // Please write your code here.
    input();
    pro(0, 0);
    if(chk){
        cout << 1;
    } else {
        cout << 0;
    }

    return 0;
}