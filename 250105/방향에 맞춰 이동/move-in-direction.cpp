#include <iostream>
using namespace std;

int dx[] = {0,-1,1,0};  //w,s,n,e
int dy[] = {-1,0,0,1};
int n;

int main() {
    // Please write your code here.
    cin >> n;
    int x,y;
    x=0;y=0;

    for(int i=0;i<n;i++){
        char c;int d;
        cin >> c >> d;
        if(c == 'W'){
            x += dx[0]*d;
            y += dy[0]*d;
        } else if(c == 'S'){
            x += dx[1]*d;
            y += dy[1]*d;
        } else if(c == 'N'){
            x += dx[2]*d;
            y += dy[2]*d;
        } else if(c == 'E'){
            x += dx[3]*d;
            y += dy[3]*d;
        }
    }

    cout << y << ' ' << x;
    return 0;
}