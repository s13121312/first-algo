#include <iostream>
using namespace std;

int n, m, q;
int arr[105][105];
int copy_arr[105][105];

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
void wind(int r1, int c1, int r2, int c2);
void rotate(int r1, int c1, int r2, int c2);
void print();

void input(){
    cin >> n >> m >> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<q;i++){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--;

        wind(r1, c1, r2, c2);
        //print();

        rotate(r1, c1, r2, c2);
    }
}


void rotate(int r1, int c1, int r2, int c2){

    for(int i=r1;i<=r2;i++){
        for(int j=c1;j<=c2;j++){
            int compo_sum = copy_arr[i][j];
            int component = 1;
            for(int d=0;d<4;d++){
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(nx<0 || nx>=n || ny<0 || ny>=m)continue;
                compo_sum += copy_arr[nx][ny];
                component++;
            }
            
            arr[i][j] = compo_sum/component;
        }
    }

}

void wind(int r1, int c1, int r2, int c2){

    int tmp1 = arr[r1][c2];
    for(int i=c2;i>=c1+1;i--){
        arr[r1][i] = arr[r1][i-1];
    }
    int tmp2 = arr[r2][c2];
    for(int i=r2;i>=r1+2;i--){
        arr[i][c2] = arr[i-1][c2];
    }
    arr[r1+1][c2]= tmp1;

    int tmp3 = arr[r2][c1];
    for(int i=c1;i<c2-1;i++){
        arr[r2][i] = arr[r2][i+1];
    }
    arr[r2][c2-1] = tmp2;

    
    for(int i=r1;i<=r2-2;i++){
        arr[i][c1] = arr[i+1][c1];
    }
    arr[r2-1][c1] = tmp3;


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            copy_arr[i][j] = arr[i][j];
        }
    }
    
}

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << arr[i][j]<< ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    // 여기에 코드를 작성해주세요.
    input();
    print();


    return 0;
}