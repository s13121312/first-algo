#include<bits/stdc++.h>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    string word[10] = {"zero", "one", "two", "three", "four","five", "six", "seven" , "eight", "nine"};
    string tmp;
    for(auto c : s){
        if(c>='0' && c<='9'){
            answer = answer *10 + (c-'0');
        }
        else{
            tmp += c;
            for(int i=0;i<10;i++){
                if(tmp == word[i]){
                    answer =  answer*10 + i;
                    tmp="";
                    break;
                }
            }
        }
    }

    // for(auto c : s){
    //     if(isdigit(c)){
    //         answer =answer*10 + c- '0';
    //     }else{
    //         tmp.push_back(c);
    //     }
    //     for(int i=0;i<10;i++){
    //         if(tmp == word[i]){
    //             answer = answer*10 + i;
    //             tmp="";//초기화
    //             break;
    //         }
    //     }
    // }
    return answer;
}