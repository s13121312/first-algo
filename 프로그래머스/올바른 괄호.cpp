#include<bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = false;
    stack<char> t;

    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            t.push('(');
        }
        if(s[i] == ')'){
            if(!t.empty()){
                t.pop();
            }
            else{
                answer=false;
                return answer;
            }
            
        }
    }
    if(t.empty()){
        answer=true;
    }
    return answer;
}