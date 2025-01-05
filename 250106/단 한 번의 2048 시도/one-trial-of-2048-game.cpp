#include <iostream>
using namespace std;

int arr[5][5];
char d;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};


void print();

void input(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin >> arr[i][j];
        }
    }
    cin >> d;

}

int rotate_tmp[5][5];

//down 기준으로 로테이트를 생각. 시계방향으로 회전
void rotate(){

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            rotate_tmp[i][j] = arr[3-j][i];
        }
    }
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            arr[i][j] = rotate_tmp[i][j];
        }
    }
}

int tmp[5][5];
int tmp2[5][5];

//dir이 D일때 1일때
void move(){
    
    //밑으로 밀고
    for(int i=0;i<4;i++){
        int end_of_idx = 3;
        for(int j=3;j>=0;j--){
            if(arr[j][i] != 0){
                tmp[end_of_idx--][i] = arr[j][i];
            }
        }
    }

    //합쳐질 수 있는지 확인
    for(int i=0;i<4;i++){
        for(int j=3;j>=1;j--){
            if(tmp[j][i] == tmp[j-1][i] && tmp[j][i] != 0){
                tmp[j][i] *=2;
                tmp[j-1][i] = 0;
            }
        }
    }

    //다시 밑으로 밀기
    for(int i=0;i<4;i++){
        int end_of_idx = 3;
        for(int j=3;j>=0;j--){
            if(tmp[j][i] != 0){
                tmp2[end_of_idx--][i] = tmp[j][i];
            }
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            arr[i][j] = tmp2[i][j];
        }
    }

}

void pro(){
    if(d == 'D'){
        move();
    } else if(d == 'R'){
        rotate();
        move();
        rotate();
        rotate();
        rotate();
    } else if(d == 'U'){
        rotate();
        rotate();
        move();
        rotate();
        rotate();
    } else if(d == 'L'){
        rotate();
        rotate();
        rotate();
        move();
        rotate();
    }
}

void print(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    // Please write your code here.
    input();
    pro();
    
    print();


    return 0;
}