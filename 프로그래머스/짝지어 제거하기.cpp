#include<bits/stdc++.h>
#include<stack>
using namespace std;

int solution(string s)
{
    int answer = 0;

    stack<char> stk;
    for(int i=0;i<s.size();i++){
        if(stk.empty()){
            stk.push(s[i]);
        }
        else if(stk.top() == s[i]){
            stk.pop();            
        }
        else{
            stk.push(s[i]);
        }
        
    }
    if(stk.empty()){
       answer = 1; 
    }
    
    return answer;
}
int main(void){

    
    return 0;
}