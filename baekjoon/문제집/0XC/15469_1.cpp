#include<bits/stdc++.h>
using namespace std;

int n, m;
bool isused[9];
int arr[9];
void dfs(int depth){

    if(depth == m){
        for(int i=0;i<m;i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(isused[i])continue;
        isused[i] = true;
        arr[depth] = i;
        dfs(depth + 1);
        isused[i]=false;
    }
    

}


int main(void){

    
    cin >> n >> m;

    dfs(0);


    return 0;
}