#include<bits/stdc++.h>
using namespace std;

int n;
int arr[35][35];
int maxval = 0;

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

}

//i,j가 구분선일때
void calc(int x, int y){
    
    int tmp[5] = {0};

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<x && j<y){
                tmp[0] += arr[i][j];
            } else if(i>=x && j<y){
                tmp[1] += arr[i][j];
            } else if(i<x && j>=y){
                tmp[2] += arr[i][j];
            } else{
                tmp[3] += arr[i][j];
            }
        }
    }

    int candidate[5] = {0};
    candidate[0] = (tmp[0]+tmp[1])*tmp[2]*tmp[3];
    candidate[1] = (tmp[0]+tmp[2])*tmp[1]*tmp[3];
    candidate[2] = (tmp[2]+tmp[3])*tmp[0]*tmp[1];
    candidate[3] = (tmp[1]+tmp[3])*tmp[0]*tmp[2];

    for(int i=0;i<4;i++){
        maxval = max(maxval, candidate[i]);
    }

}

void pro(){
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            calc(i,j);
        }
    }
    cout << maxval;
}

int main(){

    input();
    pro();
    return 0;
}