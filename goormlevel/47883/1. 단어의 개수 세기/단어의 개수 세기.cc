#include<bits/stdc++.h>
using namespace std;

string str;

void input(){
    int ans = 0;

    getline(cin, str);

    bool chk = false;
    for(int i=0;i<str.size();i++){
        if(str[i] == ' '){
            chk = false;
            continue;
        }
        else{
            if(!chk){
                ans++;
                chk = true;
            }
        }
    }

    cout << ans;
}

int main(){

    input();

    return 0;
}