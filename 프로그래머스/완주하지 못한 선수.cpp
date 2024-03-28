#include<bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    map<string,int> l1;
    map<string,int> l2;
    for(int i=0;i<participant.size();i++){
        l1[participant[i]]++;
    }
    for(int i=0;i<completion.size();i++){
        l2[completion[i]]++;
    }
    
    for(int i=0;i<completion.size();i++){
        if(l2.find(participant[i]) != l2.end()){
            if(l2[participant[i]] != l1[participant[i]]){
                answer += participant[i];
                break;
            }
        }
        else{
            answer += participant[i];
            break;
        }
    }

    if(answer == ""){
        answer +=participant[participant.size()-1];
    }

    return answer;
}