#include <iostream>
using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};  //S W N E
int x = 0,y = 0;
int n;

void move(char a, int w){
    if(a == 'S'){
        x += dx[0]*w;
        y += dy[0]*w;
    }
    if(a == 'W'){
        x += dx[1]*w;
        y += dy[1]*w;
    }
    if(a == 'N'){
        x += dx[2]*w;
        y += dy[2]*w;
    }
    if(a == 'E'){
        x += dx[3]*w;
        y += dy[3]*w;
    }
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++){
        char a;
        int w;
        cin >> a >> w;
        move(a,w);
        //cout << y << ' ' << x << '\n';
    }
    cout << y << ' ' << x;
    return 0;
}