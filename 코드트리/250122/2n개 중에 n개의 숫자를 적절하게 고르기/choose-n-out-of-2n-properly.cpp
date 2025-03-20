#include <bits/stdc++.h>
using namespace std;
int n;

int arr[25];
int total = 0;
int ans = 0x7fffffff;

void input(){
    cin >> n;
    for(int i=0;i<2*n;i++){
        cin >> arr[i];
        total += arr[i];
    }
}

//뽑은 개수 cnt
void pro(int depth, int cnt, int sum){
    if(cnt == n){
        ans = min(ans, abs(sum - (total-sum)));
        
        return;
    }

    if(depth == 2*n){
        return;
    }

    pro(depth+1, cnt+1, sum+arr[depth]);

    pro(depth+1, cnt, sum);
}


int main() {
    // Please write your code here.
    input();
    pro(0, 0, 0);
    cout << ans;
    return 0;
}