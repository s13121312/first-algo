#include <bits/stdc++.h>
using namespace std;

int n;
string str;

void input(){
    cin >> str;
}

//한 번 쉬프트 하는 
void shift(){
    char tmp = str[str.size()-1];

    for(int i=str.size()-1;i>=1;i--){
        str[i] = str[i-1];
    }
    str[0] = tmp;
}

int run_length_encoding(){
    char cur;
    char pre;
    int comp = 1;
    string res = "";


    bool chk =false; //같으면 true

    for(int i=1;i<str.size();i++){
        cur=str[i];
        pre = str[i-1];
        if(cur != pre){
            res += pre;
            res += to_string(comp); 
            comp = 0;
            chk =false;
        }
        comp++;
        chk = true;
    }
    if(chk){
        res += pre; 
        res += to_string(comp);
    }else {
        res += cur;
        res += to_string(comp);
    }
    //cout << res << '\n';
    return res.size();
}

void pro(){
    int ans = 1e9;

    ans = min(run_length_encoding(), ans);
    for(int i=0;i<str.size();i++){
        shift();
        ans = min(run_length_encoding(),ans);
        //cout << i << "-> ans: "<< ans << '\n';
    }

    cout << ans;
}   

int main() {
    // 여기에 코드를 작성해주세요.

    input();
    pro();
   
    return 0;
}