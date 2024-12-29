#include <bits/stdc++.h>
using namespace std;

int arr[105][105];
int n;

int dx[] = {-1,-1,1,1};
int dy[] = {1,-1,-1,1};
void print();

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

}

void pro(){

    int r,c, m1,m2,m3, m4, dir;
    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;
    r--;
    c--;

    pair<int,int> p[5];
    p[0] = {r,c};
    p[1] = {r + dx[0]*m1, c + dy[0]*m1};
    p[2] = {p[1].first + dx[1]*m2, p[1].second + dy[1]*m2};
    p[3] = {p[2].first + dx[2]*m3, p[2].second + dy[2]*m3};
    
    
    if(dir == 0){
        //반시계

        int tmp1 = arr[p[1].first][p[1].second];
        int cx, cy;
        cx = p[1].first; cy = p[1].second;

        for(int i=1;i<=m1;i++){
            int nx = p[1].first + dx[2]*i;
            int ny = p[1].second + dy[2]*i; 
            arr[cx][cy] = arr[nx][ny];
            cx = nx; cy=ny; 
        }

        cx = p[2].first; cy = p[2].second;
        int tmp2 = arr[p[2].first][p[2].second];
        
        for(int i=1;i<=m2-1;i++){
            int nx = p[2].first + dx[3]*i;
            int ny = p[2].second + dy[3]*i; 
            arr[cx][cy] = arr[nx][ny];
            cx = nx; cy=ny; 
        }
        arr[p[1].first + dx[1]][p[1].second + dy[1]] = tmp1;


        cx = p[3].first; cy = p[3].second;
        int tmp3 = arr[p[3].first][p[3].second];

        for(int i=1;i<=m3-1;i++){
            int nx = p[3].first + dx[0]*i;
            int ny = p[3].second + dy[0]*i; 
            arr[cx][cy] = arr[nx][ny];
            cx = nx; cy=ny; 
        }
        arr[p[2].first + dx[2]][p[2].second + dy[2]] = tmp2;
        


        cx = p[0].first; cy = p[0].second;
        for(int i=1;i<m4-1;i++){
            int nx = p[0].first + dx[0]*i;
            int ny = p[0].second + dy[0]*i; 
            arr[cx][cy] = arr[nx][ny];
            cx = nx; cy=ny; 
        }
        arr[p[3].first + dx[3]][p[3].second + dy[3]] = tmp3;
    } 
    
    else if(dir == 1){
        
        //시계방향
        int tmp1 = arr[p[3].first][p[3].second];
        int cx, cy;
        cx = p[3].first; cy = p[3].second;

        for(int i=1;i<=m4;i++){
            int nx = p[3].first + dx[3]*i;
            int ny = p[3].second + dy[3]*i; 
            arr[cx][cy] = arr[nx][ny];
            cx = nx; cy=ny; 
        }

        // cout << "1번째\n";
        // print();

        cx = p[2].first; cy = p[2].second;
        int tmp2 = arr[p[2].first][p[2].second];
        
        for(int i=1;i<=m3-1;i++){
            int nx = p[2].first + dx[2]*i;
            int ny = p[2].second + dy[2]*i; 
            arr[cx][cy] = arr[nx][ny];
            cx = nx; cy=ny; 
        }
        arr[p[3].first + dx[0]][p[3].second + dy[0]] = tmp1;
        
        // cout << "2번째\n";
        // print();

        cx = p[1].first; cy = p[1].second;
        int tmp3 = arr[p[1].first][p[1].second];

        for(int i=1;i<=m2-1;i++){
            int nx = p[1].first + dx[1]*i;
            int ny = p[1].second + dy[1]*i; 
            arr[cx][cy] = arr[nx][ny];
            cx = nx; cy=ny; 
        }
        arr[p[2].first + dx[3]][p[2].second + dy[3]] = tmp2;

        // cout << "3번째\n";
        // print();


        cx = p[0].first; cy = p[0].second;
        for(int i=1;i<=m1-1;i++){
            int nx = p[0].first + dx[0]*i;
            int ny = p[0].second + dy[0]*i; 
            arr[cx][cy] = arr[nx][ny];
            cx = nx; cy=ny; 
        }
        arr[p[1].first + dx[2]][p[1].second + dy[2]] = tmp3;

        // cout << "4번째\n";
        // print();

    }

}

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    input();
    pro();
    print();

    return 0;
}