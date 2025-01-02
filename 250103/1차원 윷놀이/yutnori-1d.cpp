#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int arr[15];
bool chk[5];
int cur[105];

int ans =0;
void input(){
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<m;i++)cur[i]= 1;
}

void backtracking(int idx, int score){
    ans = max(ans, score);
    if(idx == n){
        
        return;
    }


    for(int i=1;i<=k;i++){
        if(cur[i] >= m)continue;  //for루프에서 커트 해버리기때문에 ans초기화할때 조건문 바깥에 놔둬야함
        cur[i] += arr[idx];
        int new_score = (cur[i] >= m) ? score+1 : score;
    
        backtracking(idx+1, new_score);
        cur[i] -= arr[idx];
    }
}


int main() {
    // Please write your code here.
    input();
    backtracking(0, 0);
    cout << ans;

    return 0;
}