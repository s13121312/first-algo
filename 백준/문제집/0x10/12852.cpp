#include<bits/stdc++.h>
using namespace std;

int d[1000005];
int pre[1000005];
int main(void){

    int n;
    cin >> n;

    d[1]=0;
    for(int i=2;i<=n;i++){
        d[i]=d[i-1]+1;
        pre[i]=i-1;
        //dp[i]에 dp[i-1], dp[i/3], dp[i/2]중에 가장 연산의 길이가 짧은 것을 대입
        if(i%3==0 && d[i]>d[i/3]+1){//d[i]가 큰것이 의미하는게 d[i/3]이 더 짧은길이를갖고있다느것
            d[i]=d[i/3]+1;
            pre[i]=i/3;
        }
        if(i%2==0 && d[i]>d[i/2]+1){
            d[i]=d[i/2]+1;
            pre[i]=i/2;
        }
        
    }
    cout << d[n] << '\n';
    int cur =n;
    while (true)
    {
        cout << cur <<' ';
        if(cur==1) break;
        cur = pre[cur];
    }
    


    return 0;
}