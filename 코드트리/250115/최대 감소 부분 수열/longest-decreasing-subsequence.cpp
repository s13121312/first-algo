#include <iostream>
using namespace std;

int n;
int ans = 0;
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
        dp[i] = 1;
    }
}

void pro(){
    init();

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] < arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    

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