#include<bits/stdc++.h>
using namespace std;

int n;
int t[25], p[25];

int maxVal = 0;


void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        int tv, pv;
        cin >> tv >> pv;
        t[i] = tv;
        p[i] = pv;
    }
}


void pro2(int day, int income){
    if(day >= n+1)return;
    
    if(day == n){
        maxVal = max(maxVal, income);
        return;
    }

    //선택안할때때
    pro2(day+1, income);

    //해당일에 일을 선택
    pro2(day + t[day], income + p[day]);
    
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    //pro(0);
    pro2(0,0);
    cout << maxVal;

    return 0;
}