#include <bits/stdc++.h>
using namespace std;

int n;
int t[20], p[20];
int dp[20]; //i일 일때 최대 의 수익

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> t[i] >> p[i];
    }
}

void init(){
    for(int i=1;i<=n;i++){
        dp[i] = 0;
    }
}

void print(){
    for(int i=1;i<=n;i++)cout << dp[i] << ' ';
    cout << '\n';
}
void pro(){

    init();
    dp[0] = 0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(i >= j + t[j]){
                dp[i] = max(dp[i], dp[i - t[j]] + p[j]);
            }
        }
    }

    //print();

    cout << dp[n];
}

int main() {
    // Please write your code here.
    input();
    pro();



    return 0;
}