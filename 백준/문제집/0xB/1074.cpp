#include<bits/stdc++.h>
using namespace std;

int func(int n, int r, int c){

    if(n==0)return 0;
    int half=1;
    for(int i=0;i<n-1;i++){
        half *= 2;
    }
    //half = 2의 n-1승  int half = 1 << (n-1)로도 표현가능

    if(r < half && c <half){
        return func(n-1, r, c);
    }
    else if(r < half && c >= half){
        return half*half + func(n-1, r, c-half);
    }
    else if(r >= half && c < half){
        return 2*half*half + func(n-1, r-half, c);
    }
    else{ // r >=절반 c >=절반
        return 3*half*half + func(n-1, r-half, c-half);
    }

}
int main(void){

    int n, r, c;
    cin >> n >> r >> c;
    cout << func(n, r, c);

    return 0;
}