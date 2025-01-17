#include <bits/stdc++.h>
using namespace std;

int n;
int arr[105];
int dp[105];

int total=0;
int half;

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        total += arr[i];
    }
    half = total/2;
    
    dp[0] = 0;
    for(int i=1;i<=total;i++){
        dp[i] = INT_MIN;
    }
}

void print(){
    for(int i=1;i<=total;i++){
        cout << dp[i] << ' ';
    }
    cout << '\n';

}
void pro(){

    for(int i=0;i<n;i++){
        for(int j=total;j>=1;j--){
            if(j >= arr[i]){
                dp[j] = max(dp[j], dp[j - arr[i]] + 1);
            }
        }
    }
    //print();

    if(dp[half] > 0 && total%2  == 0){
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