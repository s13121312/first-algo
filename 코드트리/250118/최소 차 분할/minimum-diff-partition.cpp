#include <bits/stdc++.h>
using namespace std;

int n;
int arr[105];
bool dp[105][100005]; // i번째 고려했을 때 j를 만들 수 있는지
int total =0;
int ans = 0x7fffffff;

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        total += arr[i];
    }
    dp[0][0] = false;
}


void pro(){
    
    for(int i=0;i<n;i++){
        for(int j=1;j<=total;j++){
            //i번째거를 선택했을때
            if(j >= arr[i] && dp[i-1][j-arr[i]]){
                dp[i][j] = true; 
            }

            //안했을때
            if(dp[i-1][j]) dp[i][j] = dp[i-1][j]; 
        }
    }


    for(int j=1;j<=total;j++){
        if(dp[n-1][j]){
            ans = min(ans, abs(total-j-j));
        }
    }
    cout << ans;

}

int main() {
    // Please write your code here.
    input();
    pro();

    return 0;
}