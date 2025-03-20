#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[25];
int ans = 0;
vector<int> v;

void input(){
    cin >> n >>m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
}

void pro(int cur, int cnt,int val){
    if(cnt == m){
        ans = max(ans, val);
    }

    if(cur == n){
        return;
    }
    
    pro(cur+1,cnt, val);

    pro(cur + 1, cnt+1, val^ arr[cur]);
}

int main() {
    // Please write your code here.
    input();
    pro(0, 0, 0);
    cout << ans;


    return 0;
}