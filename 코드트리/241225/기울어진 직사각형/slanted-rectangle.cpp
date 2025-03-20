#include <bits/stdc++.h>
using namespace std;
/*
기울어진 직사각형이란, 
격자내에 있는 한 지점으로부터 체스의 비숍처럼 대각선으로 움직이며 반시계 순회를 했을 때 
지나왔던 지점들의 집합을 일컫습니다. 

이 때 반드시 아래에서 시작해서 1, 2, 3, 4번 방향순으로 순회해야하며 
각 방향으로 최소 1번은 움직여야 합니다. 

또한, 이동하는 도중 격자 밖으로 넘어가서는 안됩니다.
*/

int arr[105][105];
int n;
int dx[] = {-1,-1,1,1};
int dy[] = {1,-1,-1,1};

bool out_range(int nx, int ny){
    return (nx<0 || nx>=n || ny<0 || ny>=n);
}

int ans = 0;

int make_rec(int x, int y, int w, int h){
    
    int sum = 0;
    
    int nx = x;
    int ny = y;

    int move_size[] = {w,h,w,h};
    for(int i=0;i<4;i++){
        for(int j=0;j<move_size[i];j++){
            nx += dx[i];
            ny += dy[i];
            if(out_range(nx, ny))return 0;

            sum += arr[nx][ny];
        }
        
    }
    return sum;
    
}

void pro(){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int w = 1;w<=n;w++){
                for(int h=1;h<=n;h++){
                    ans = max(ans, make_rec(i,j,w,h));
                }
            }
        }
    }

    cout << ans;
}

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    input();

    pro();

    return 0;
}