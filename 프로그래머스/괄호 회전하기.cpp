#include <bits/stdc++.h>
using namespace std;

char gualho_open[4] = {'(','[','{'};
char gualho_close[4] = {')',']','}'};

bool check(string input){
    bool ch = false;

    stack<char> t;
    for(int i=0;i<input.length();i++){
        for(int j=0;j<3;j++){
            if(input[i]==gualho_open[j]){
                t.push(input[i]);
                break;
            }
            if(input[i]==gualho_close[j]){
                if(!t.empty()){
                    if(t.top()==gualho_open[j]){
                        t.pop();
                        break;
                    }
                    else{
                        ch =false;
                        return ch;
                    }
                }
                else{
                    ch = false;
                    return ch;
                }
            }
        }

    }
    if(t.empty()){
        ch = true;
    }
    return ch;
}

int solution(string s) {
    int answer = 0;
    
    // 회전
    for(int i=0;i<s.length();i++){
        string first = s.substr(0,1); //첫번째 글자 빼기

        string tmp = s.substr(1,s.length()-1);
        s = tmp + first;
        if(check(s)){
            answer++;
        }
    }
    return answer;
}

int main(void){
    string s = "[](){}";
    cout << solution(s);
}

