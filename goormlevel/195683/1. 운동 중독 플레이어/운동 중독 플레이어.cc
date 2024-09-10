#include<bits/stdc++.h>
using namespace std;

int w, r;

void input(){
    cin >> w >> r;
}

void pro(){
    int result = 0;
    double pl = r/30.0;
    //cout << "pl: " << pl << '\n';
    result = w * (1 + pl);
    cout << result;
}

int main(){

    input();
    pro();

    return 0;
}