//다시풀기
#include<bits/stdc++.h>
using namespace std;

int func(int n){
    if(n == 1){
        return 1;
    }
    int cnt=0;  
    int a=2;
    //1    23456   8910111213141516171819
    int c;
    int b = 6;

    for(int sum=2; sum <= n;i++){
        if(n >= a && n < c){
            return cnt;
        }
        else{
            a += b*i;
            c = a + b*i;
            cnt++;
        }   
    }
}

int main(void){


    int n;
    cin >> n;

    cout << func(n);

    return 0;
}