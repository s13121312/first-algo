#include<bits/stdc++.h>
using namespace std;

int n, ans = 0;
int arr[1000005];
int cnt[1000005];
//int dp[1000005];  //dp[i]는 i번째값을 가지면서 최대개수
const int MAX = 1000007;

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }

}

//가져가는 원소들의 최대공약수는 2 이상이어야한다.
void pro(){
    
    for(int i=2;i<MAX;i++)   //최대 공약수가 i일때 완전탐색해버림
    {
        int cur =0;
        for(int j=i;j<MAX;j+=i){
            cur += cnt[j];
        }
        ans = max(ans, cur);
    }

    cout << ans;
}
//a>b
int gcd(int a, int b){
    if(b == 0)return a;
    return gcd(b, a%b);   
}

int main(){

    input();
    pro();


    return 0;
}