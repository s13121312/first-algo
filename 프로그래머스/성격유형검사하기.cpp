#include<bits/stdc++.h>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";

    vector<vector<char>> jip = { {'R','T'},{'C','F'},{'J','M'},{'A','N'}};

    unordered_map<char,int> m;
    
    int score[8]={0,3,2,1,0,1,2,3};

    for(int i=0;i<choices.size();i++){
        
        if(score[choices[i]]==3){
            if(choices[i]==1){
                m[survey[i][0]] +=3;
            }else{
                m[survey[i][1]] +=3;
            }
        }
        else if(score[choices[i]]==2){
            if(choices[i] == 2){
                m[survey[i][0]] +=2;
            }else{
                m[survey[i][1]] +=2;
            }
        }
        else if(score[choices[i]]==1){
            if(choices[i] == 3){
                m[survey[i][0]] +=1;
            }else{
                m[survey[i][1]] +=1;
            }
        }
        else{
            continue;
        }
    }

    for(int i=0;i<jip.size();i++){
        if(m[jip[i][0]] > m[jip[i][1]]){
            answer += jip[i][0];
        }
        else if(m[jip[i][0]] < m[jip[i][1]]){
            answer += jip[i][1];
        }
        else{ //같을때
            char c;
            if(jip[i][0] < jip[i][1]){
                c=jip[i][0];
            } 
            if(jip[i][0] > jip[i][1]){
                c = jip[i][1];
            } 
            answer += c; 
        }
    }

    return answer;
}