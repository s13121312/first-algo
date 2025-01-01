#include <iostream>
using namespace std;

int n, r, c;
int arr[205][205];
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

int tmp[205][205];
void print();

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    cin >> r >> c;
    r--;
    c--;
}

void pro(){
    int bomb_size = arr[r][c];

    for(int d=0;d<4;d++){
        for(int k =0;k<bomb_size;k++){
            int nx = r + dx[d]*k;
            int ny = c + dy[d]*k;

            if(nx<0 ||nx>n || ny <0 || ny> n)continue;
            arr[nx][ny] = 0;
        }
    }

    //print();
    
    for(int i=0;i<n;i++){
        int idx =n-1;
        for(int j=n-1;j>=0;j--){
            if(arr[j][i] != 0){
                tmp[idx][i]= arr[j][i];
                idx--;
            }
        }    
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = tmp[i][j];
        }
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