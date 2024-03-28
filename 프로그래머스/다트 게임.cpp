#include <bits/stdc++.h>
using namespace std;

int solution(string dartResult)
{
    int answer = 0;

    string num = "";

    int order=0;
    vector<int> r;
    for(int i=0;i<dartResult.size();i++){
        if(dartResult[i] >='0' && dartResult[i] <='9') num += dartResult[i];
        
        else if(dartResult[i]=='S'){
            r.push_back(stoi(num));
            num = "";
            order++;
        }
        else if(dartResult[i]=='D'){
            r.push_back((stoi(num))*(stoi(num)));
            num = "";
            order++;
        }
        else if(dartResult[i]=='T'){
            r.push_back((stoi(num))*(stoi(num))*(stoi(num)));
            num = "";
            order++;   
        }
        else if(dartResult[i]=='*'){
            //TODO 지금것과 전, 두개점수를 2배해야함
            r[order-1] *= 2;
            
            if(order>=2){
                r[order-2] *= 2;
            }
            
        }
        //if(dartResult[i]=='#'){
        else{
            r[order-1] *= -1;
        }   
    }


    for(int i=0;i<3;i++){
        answer += r[i];
    }

    return answer;
}