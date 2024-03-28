#include<bits/stdc++.h>
using namespace std;

int arr[505][505];  // w h

int main(void){

    int w, h;
    cin >> h >> w;

    for(int i=0;i<w;i++){
        int t;
        cin >> t;
        for(int j=h-1;j>=h-t;j--){
            arr[i][j] = 1;
        }


    }

    return 0;
}