#include <bits/stdc++.h>

using namespace std;

int n;
int arr[15][15];
bool vis[15]; //열
int ans = 0;

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
}
vector<pair<int, int>> v;

int calc(){
    int sum = 0;
    for(auto x: v){
        sum += arr[x.first][x.second];
    }

    return sum;
}

void printcoma(){
    for(auto x: v){
        cout << x.first << ' ' << x.second << '\n';
    }
    cout << '\n';
}

void pro(int row){
    if(row == n){
        ans = max(ans, calc());
        //printcoma();
        return;
    }


    for(int i=0;i<n;i++){
        if(vis[i])continue;
        v.push_back({row, i});
        vis[i] = true;
        pro(row + 1);
        v.pop_back();
        vis[i] = false;
        
    }


}

int main() {
    // Please write your code here.
    input();
    pro(0);
    cout << ans;

    return 0;
}