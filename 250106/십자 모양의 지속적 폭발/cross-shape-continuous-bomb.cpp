#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[205][205];
int tmp[205][205];

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
vector<int> v;

void pro(int c);
void gravity();

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        int c;
        cin >> c;
        c--;
        v.push_back(c);
        
    }

    for(auto x: v){
        pro(x);
        //print();
        //cout <<'\n';
    }
}

//c열의 가장 위에 있는칸을 중심으로 터짐
void bomb(int x, int y){
    int ix = x;
    int iy = y;
    int size = arr[ix][iy];
    arr[ix][iy] = 0;

    for(int j=1;j<size;j++){
        for(int d=0;d<4;d++){
            int nx = ix + dx[d]*j;
            int ny = iy + dy[d]*j;
            if(nx<0 || nx>=n || ny<0 || ny>=n || arr[nx][ny] == 0)continue;
            //cout << nx << ' ' << ny << '\n';
            arr[nx][ny] = 0;
        }
    }
    
}

void pro(int c){
    for(int i=0;i<n;i++){
        if(arr[i][c] != 0){
            //폭탄 터뜨리고 나가기
            bomb(i, c);
            break;
        }
    }

    //중력 작용
    gravity();
}

void gravity(){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tmp[i][j] = 0;
        }
    }

    for(int i=0;i<n;i++){
        int end_of_idx = n-1;
        for(int j=n-1;j>=0;j--){
            if(arr[j][i] != 0){
                tmp[end_of_idx--][i] = arr[j][i];
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = tmp[i][j];
        }
    }
}

int main() {
    // Please write your code here.
    input();

    print();

    return 0;
}