//너무 복잡하게 풀려고한다..!

#include<bits/stdc++.h>
using namespace std;

vector<pair<char,string>> term;
vector<pair<int,char>> d; //terms랑 privacies 더한값을 저장하는

void func(vector<string> &privacies){

    char space = ' ';
    for(int i=0;i<privacies.size();i++){
        string date = "";
        for(int j=0;j<privacies[i].size();j++){
            if(privacies[i][j] != space){
                date += privacies[i][j];
            }
            else{
                d[i].first = stoi(date.substr(0,4))*28*12 + stoi(date.substr(5,2))*28 + stoi(date.substr(8,2));
                d[i].second = privacies[i].back();
                date ="";
                break;
            }
        }      
    }

    for(int i=0;i<d.size();i++){
        if(find(term.begin(),term.end(),d[i].second) != term.end()){
            int k = find(term.begin(),term.end(),d[i].second)-term.begin();
            int plus = stoi(term[k].second); // 더해야할값
            d[i].first += plus;          
        }
    }

}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    string num ="";
    
    for(int i=0;i<terms.size();i++){
        
        term[i].first = terms[i][0];
        for(int j=2;j<terms[i].size();j++){
            num += terms[i][j];
        }
        term[i].second = num;
    }

    func(privacies);
    //TODO today와 func함수돌린값이랑비교
    for(int i=0;i<d.size();i++){
        int day = stoi(today.substr(0,4))*28*12 + stoi(today.substr(5,2))*28 + stoi(today.substr(8,2));
        if(d[i].first<=day){
            continue;
        }
        else{
            answer.push_back(i+1);
        }
    }
    

    return answer;
}