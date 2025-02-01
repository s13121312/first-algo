#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<string> arr;
string order;

int dx[] = {0,1,0,-1};   // R,D,L,U 순서
int dy[] = {1,0,-1,0};
void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        arr.push_back(s);
    }
    cin >> order;
}

void print(){
    for(int i=0;i<n;i++){
        cout << arr[i] << '\n';
    }
}


void move(int dir, vector<string> tmp){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = '.';
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int nx = i + dx[dir];
            int ny = j + dy[dir];
            if(nx<0)nx = n-1;
            if(nx>=n)nx = 0;
            if(ny<0)ny = n-1;
            if(ny>=n)ny = 0;

            if(tmp[i][j] == 'X')arr[nx][ny] = 'X'; 
        }
    }


}

void pro(){
    for(char d : order){
        if(d == 'R')move(0, arr);
        else if(d == 'D')move(1, arr);
        else if(d == 'L')move(2, arr);
        else if(d == 'U')move(3, arr);
    }
    print();

}

int main(){

    input();
    pro();

    return 0;
}