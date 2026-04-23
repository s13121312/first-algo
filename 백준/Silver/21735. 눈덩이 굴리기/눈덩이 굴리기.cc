#include<bits/stdc++.h>
using namespace std;
int n, m;
int arr[105];
int ans = 0;

void dfs(int idx, int cnt, int total) {
    if(cnt > m)return;
    if(idx>=n || cnt == m) {
        ans = max(ans, total);
        return;
    }
    if(idx+1 <= n)dfs(idx+1, cnt+1, total + arr[idx+1]);
    if(idx+2 <= n)dfs(idx+2, cnt+1, (total/2)+arr[idx+2]);
}


int main(void) {

    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }    

    dfs(0, 0, 1);
    cout << ans;

    return 0;
}