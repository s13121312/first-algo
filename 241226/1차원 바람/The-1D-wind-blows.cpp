#include <bits/stdc++.h>
using namespace std;

int n, m ,q;
int arr[105][105];

void input(){
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
        }
    }
}


void shift(int r, char d){
    if(d == 'L'){
        int tmp = arr[r][m];
        for(int i=m;i>=2;i--){
            arr[r][i] = arr[r][i-1];
        }
        arr[r][1] = tmp;

    } else if(d == 'R'){
        int tmp = arr[r][1];
        for(int i=1;i<m;i++){
            arr[r][i] = arr[r][i+1];
        }
        arr[r][m] = tmp;
    }
}

bool isSameRow(int r1, int r2){
    if(r1<1 || r1>n || r2 <1 || r2>n)return false;
    for(int i=1;i<=m;i++){
        if(arr[r1][i] == arr[r2][i]){
            return true;
        }
    }
    return false;
}


void pro(){
    for(int i=0;i<q;i++){
        int r;
        char d;
        cin >> r >> d;   //행 번호, 방향(L이면 오른쪽으로 밀림, R이면 왼쪽으로 밀림)

        shift(r, d);
        //cout << "shift"<< '\n';
        //if(n == 1)break;
        char cur_d = (d == 'L')? 'R' : 'L';

        for(int j=r-1;j>=1;j--){
            //이 행이  전파가 가능한지 체크하고 안되면 break / 되면 shift.
            if(!isSameRow(j,j+1))break;

            shift(j, cur_d);
            //cout << "shift"<< '\n';
            cur_d = (cur_d == 'L') ? 'R' : 'L';
        }

        cur_d = (d == 'L')? 'R' : 'L';
        for(int j=r+1;j<=n;j++){
            if(!isSameRow(j-1,j))break;

            shift(j, cur_d);
            //cout << "shift"<< '\n';
            cur_d = (cur_d == 'L') ? 'R' : 'L';
        }
    }
}
void print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {

    input();
    pro();
    
    print();
    return 0;
}