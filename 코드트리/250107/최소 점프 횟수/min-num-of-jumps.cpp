#include <bits/stdc++.h>
using namespace std;

int n;
int arr[15];
vector<int> v;
bool vis[15];

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
}
int ans = 0x7fffffff;

void pro(int cur, int cnt){
    if(cur == n-1){
        ans = min(ans, cnt);
        return;
    }


    for(int i=1;i<=arr[cur];i++){
        if(cur+i >= n)continue;
        vis[cur+i] = true; 
        pro(cur+i, cnt+1);
        vis[cur+i] = false;
    }
}


int main() {
    // Please write your code here.
    input();
    pro(0, 0);
    if(ans == 0x7fffffff){
        cout << -1;
    } else{
        cout << ans;
    }

    return 0;
}