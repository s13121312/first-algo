#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
int arr[25][25];
vector<pair<int, int>> pos;
int ans = 0;

int copyarr[25][25];

//중심 기준으로 폭탄 방향
int bomb[3][4][2] = {
    
        {   {-2,0},
            {-1,0},
            {1,0},
            {2,0}
        },
        {
            {1,0},
            {0,-1},
            {-1,0},
            {0,1}
        },
        {
            {-1,-1},
            {-1,1},
            {1,1},
            {1,-1}
        },
    
};

int calc(){
    int tmp =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 1)tmp++;
        }
    }
    return tmp;
}

void pung(int x, int y, int bombType){
    arr[x][y] = 1;
    for(int i=0;i<4;i++){
        int nx = x + bomb[bombType][i][0];
        int ny = y + bomb[bombType][i][1];
        if(nx<0 || nx>=n || ny<0 || ny >= n)continue;
        arr[nx][ny] = 1;
    }
            
}

void backtracking(int idx){
    if(idx == pos.size()){
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout << arr[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        ans = max(ans, calc());
        return;
    }

    for(int t=0;t<3;t++){
        int copyarr[25][25];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                copyarr[i][j] = arr[i][j];
            }
        }
        //폭탄 터뜨리기
        pung(pos[idx].first, pos[idx].second, t);

        backtracking(idx+1);
        
        //폭탄 터뜨리기 전으로 복구
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j] = copyarr[i][j];
            }
        }

    }

}

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                pos.push_back({i,j});
            }
        }
    }
}

void pro(){
    cout << ans;

}


int main() {
    // 여기에 코드를 작성해주세요.
    input();
    backtracking(0);
    pro();

    return 0;
}