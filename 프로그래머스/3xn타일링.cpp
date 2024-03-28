//점화식구하기 개어려움 
#include<bits/stdc++.h>
using namespace std;

long long d[5005][5];
int sum[5005];

int solution(int n){

    if(n%2==1){
        cout << "0";
        return 0;
    }
    d[2][0]=1;
    d[2][1]=1;
    d[2][2]=1;
    d[4][0]=4;
    d[4][1]=4;
    d[4][2]=3;
    //6일때 만들어지느 모양이 2개있다!
    sum[2]=3;
    sum[4]=11;
    //짝수만
    for(int i=6;i<=n;i++){
        d[i][0]=(d[i-2][0]+d[i-2][1]+d[i-2][2]+d[i-4][0]+d[i-4][1]+d[i-4][2])%1000000007;
        d[i][1]=(d[i-2][0]+d[i-2][1]+d[i-2][2]+d[i-4][0]+d[i-4][1]+d[i-4][2])%1000000007;
        d[i][2]=(d[i-2][0]+d[i-2][1]+d[i-2][2])%1000000007;

        sum[i]=(d[i][0]+d[i][1]+d[i][2])%1000000007;
    }
    
    return sum[n];
}  

int main(void){

    int n;
    cin >> n;
    cout << solution(n);

    return 0; 
}