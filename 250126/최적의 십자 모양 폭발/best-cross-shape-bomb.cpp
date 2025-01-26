#include <iostream>
using namespace std;
int n;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int arr[55][55];
int tmp1[55][55];
int afterBomb[55][55];
int ans = -1;

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
}

void init(int a[55][55]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j] = 0;
        }
    }
}

//2개로 이뤄진 쌍의 개수 찾기
int checktwin(){
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(afterBomb[i][j]==0)continue;
            if(afterBomb[i][j] == afterBomb[i][j+1])cnt++;
        }
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<n-1;i++){
            if(afterBomb[i][j]==0)continue;
            if(afterBomb[i][j] == afterBomb[i+1][j])cnt++;
        }
    }

    return cnt;
}

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << afterBomb[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

//x,y좌표에서 폭탄 터질때
void bomb(int x, int y){
    int size = arr[x][y];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tmp1[i][j] = arr[i][j];
        }
    }
    init(afterBomb);

    for(int i=0;i<4;i++){
        for(int s = 0;s<size;s++){
            int nx = x + dx[i]*s;
            int ny = y + dy[i]*s;
            if(nx<0 || nx>=n || ny<0 || ny>=n)continue;
            tmp1[nx][ny] = 0;
        }
    }

    for(int j=0;j<n;j++){
        int index_endS = n-1;
        for(int i=n-1;i>=0;i--){
            if(tmp1[i][j] != 0){
                afterBomb[index_endS--][j] = tmp1[i][j];
            }
        }
    }
    //print();

    ans = max(ans, checktwin());
    //cout << ans << ' ';
}

void pro(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            bomb(i, j);
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