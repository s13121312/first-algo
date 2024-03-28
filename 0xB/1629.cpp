#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll mod(ll a, ll b, ll c){ //a를 b번 곱한 수를 c로 나눈 나머지
    if(b==1) return a % c;
    ll val = mod(a,b/2,c);
    val = val* val %c;
    if(b%2==1) return a*val%c;         //b가 홀수일때
    else{
        return val;
    }
}

int main(void){

    ll a,b,c;
    cin >> a >> b >> c;
    cout << mod(a,b,c);


    return 0;
}