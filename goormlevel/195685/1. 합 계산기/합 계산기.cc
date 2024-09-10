#include<bits/stdc++.h>
using namespace std;

int t;
string str;
int ans = 0;
int pro(char s, int a, int b){
    if(s == '+'){
        return a+b;
    }else if(s == '-'){
        return a-b;
    }else if(s == '/'){
        return a/b;
    }else if(s == '*'){
        return a*b;
    }
}

void input(){
    cin >> t;
    cin.ignore();
    for(int z = 0;z<t;z++)
    {
        getline(cin, str);
        int a=0, b=0;
        char s;
        istringstream iss(str);
        iss >> a >> s >> b;

        ans += pro(s,a,b);      
        //cout << "a: " << a <<",b: " << b <<", ans: " << ans << '\n';
    }
    
}


int main(){

    input();
    cout << ans;
    return 0;
}