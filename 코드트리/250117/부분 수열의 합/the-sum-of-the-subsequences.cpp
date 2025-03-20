#include <bits/stdc++.h>
using namespace std;
int n, m;
bool ans;
int arr[105];
int dp[10005];

void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    dp[0] = 0;
    for(int i=1;i<=m;i++){
        dp[i] = INT_MIN;
    }
}

void print(){
    for(int i=1;i<=m;i++){
        cout << dp[i] << ' ';
    }
    cout << '\n';
}

void pro(){

    for(int i=0;i<n;i++){
        for(int j=m;j>=1;j--){
            if(j >= arr[i]){
                if(dp[j - arr[i]] == INT_MIN)continue;
                dp[j] =max(dp[j],  dp[j - arr[i]] + 1); 
            }
        }
    }
    //print();

    if(dp[m] > 0){
        ans = true;
    }else{
        ans = false;
    }

    if(ans){
        cout << "Yes";
    } else{
        cout << "No";
    }
}

int main() {
    // Please write your code here.
    input();
    pro();

    return 0;
}