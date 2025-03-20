#include <bits/stdc++.h>
using namespace std;

int n;
int s[1005], e[1005], p[1005];
int dp[1005];

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i] >> e[i] >> p[i];
    }
}
void print(){
    for(int i=0;i<n;i++){
        cout << dp[i] << ' ';
    }
    cout << '\n';
}
void pro(){
    for(int i=0;i<n;i++){
        dp[i] = p[i];
    }


    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++) {
            if(dp[j] == INT_MIN)continue;
            if(s[i] > e[j]) {
                dp[i] = max(dp[i], dp[j] + p[i]);
            }
        }
    }
    //print();
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

int main() {
    // Please write your code here.
    input();
    pro();

    return 0;
}