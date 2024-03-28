#include<bits/stdc++.h>
using namespace std;

char star[3100][6200];

void func(int n,int x,int y){ // x,y는 시작점의 위치

    if(n==3){
        star[x][y] = '*';

        star[x+1][y-1] = '*';
        star[x+1][y+1] = '*';
        
        for(int i=y-2;i<=y+2;i++){
            star[x+2][i]='*';
        }
        return;
    }

    int s = n/2;
    func(s,x,y);
    func(s,x+s,y-s); // 시작점이 어떻게 되는지를 생각해야함
    func(s,x+s,y+s);

    //x,y를 어떻게 해야할지 모르겠구만
    // for(int i=0;i<n;i++){
    //     for(int j=-2;j<=2;j++){
    //         if(i==1 && j == 0)continue;
    //         func(n/2, x+ i*n/2, y + j*n/2);
    //     }
    // }
    
}



int main(void){

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++){
            star[i][j] = ' ';
        }
    }
    func(n,0,n-1);

    for(int i=0;i<n;i++){
        for(int ii=0;ii<2*n-1;ii++){
            cout << star[i][ii];
        }
        cout << '\n';
    }

    return 0;
}