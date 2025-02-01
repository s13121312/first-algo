#include <bits/stdc++.h>
using namespace std;

int n;
int pArr[25][25];

void input(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> pArr[i][j];
        }
    }
}

bool visit[25];
vector<int> selected;
int ans = 0x7fffffff;

int minusCalc(){
    int choosed = 0;
    int unchoosed = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(visit[i] && visit[j]){
                choosed += pArr[i][j];
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(!visit[i] && !visit[j]){
                unchoosed += pArr[i][j];
            }
        }
    }


    //cout << choosed << ' ' <<unchoosed << '\n';
    return abs(choosed - unchoosed);
}
void pro(int cur, int cnt){

    if(cnt == n/2){
        ans = min(ans, minusCalc());
        // for(auto x: selected) { 
        //     cout << x << ' ';
        // }
        // cout << '\n';
        return;
    }

    for(int i=cur;i<=n;i++){
        if(!visit[i]){
            visit[i] = true;
            selected.push_back(i);
            pro(i+1, cnt+1);
            visit[i] = false;
            selected.pop_back();
        }
    }

}

int main() {
    // Please write your code here.
    input();
    pro(1,0);
    cout << ans;

    return 0;
}