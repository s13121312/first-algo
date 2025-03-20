#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1005];
int dp[1005];

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
}

void init(){
    for(int i=0;i<n;i++){
        dp[i] = INT_MIN;
    }
    dp[0] = 0;
}
void print(){
    for(int i=0;i<n;i++){
        cout << dp[i] << ' ';
    }
    cout << '\n';
}
void pro(){
    init();
    for(int i=1;i<n;i++){
        
        for(int j=0;j<i;j++){
            
            if(j + arr[j] < i)continue;
            if(arr[j] == 0)continue;
            dp[i] = max(dp[i], dp[j] + 1);

        }
    }
    int ans = 0;

    //print();

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