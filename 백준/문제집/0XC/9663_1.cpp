#include<bits/stdc++.h>
using namespace std;

int arr[15][15];
bool isused1[40];
bool isused2[40];
bool isused3[40];

int n;
int ans = 0;


//상,하,좌,우,대각선


void queen(int depth){

    if(depth == n){
        ans++;
        return;
    }
    for(int i=0;i<=n-1;i++){
        if(isused1[i] || isused2[depth+i] || isused3[depth-i+n-1])continue;
        isused1[i]=true;
        isused2[depth+i]=true;
        isused3[depth-i+n-1]=true;
        queen(depth+1);
        isused1[i]=false;
        isused2[depth+i]=false;
        isused3[depth-i+n-1]=false;
    }
    



}



int main(void){

    
    cin >> n;

    queen(0);

    cout << ans;

    return 0;
}