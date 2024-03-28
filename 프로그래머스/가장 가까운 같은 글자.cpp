#include<bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    int count =0;

    for(int i=0;i<s.size();i++){
        count = -1;
        for(int j=i-1;j>=1;j--){
            if(s[i] == s[j]){
                count = i-j;
                
                break;
            }  
        }
        answer.push_back(count);
    }
    return answer;
}