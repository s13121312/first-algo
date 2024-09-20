#include <string>
#include <vector>
#include<sstream>
#include<unordered_map>
#include<bits/stdc++.h>

using namespace std;
unordered_map<string, string> um;
unordered_map<string, int> totaltime; // 누적 주차 시간
vector<string> carnumber;
vector<pair<string, int>> preresult;

bool cmp(pair<string,int> p1, pair<string, int> p2){
    return p1.first < p2.first;
}

int timecalc(string time1, string time2){
    //time2에서 time1을 빼줘야함 
    int t1 = 60*stoi(time1.substr(0,2)) + stoi(time1.substr(3,2));
    int t2 = 60*stoi(time2.substr(0,2)) + stoi(time2.substr(3,2));
    return t2-t1;
}

void inorout(string rec, string time, string carnum){
    if(rec == "IN"){
        um[carnum] = time;
    }else if(rec == "OUT"){
        //전에 있던 시간이랑 빼서 차이계산 
        //근데 남아있는것(입차만 들어온것) 어떻게계산??
        
        totaltime[carnum] += timecalc(um[carnum], time);
        um.erase(carnum); //carnum in/out 한턴이 끝났음.
    }
}

//clear
double feecalc(string s, int basictime, int basicfee, int t, int f){
    if(totaltime[s] <= basictime){
        return basicfee;
    }
    else{
        int tmp = basicfee + (1 + ((totaltime[s] - basictime - 1)/t))*f;
        
        return tmp;
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    for(auto x : records){
        
        stringstream ss(x);

        string time, carnum, rec;
        ss >> time >> carnum >> rec;
        if(find(carnumber.begin(), carnumber.end(), carnum) == carnumber.end()){
            carnumber.push_back(carnum);
        }
        inorout(rec, time, carnum);
    }


    //혹시 in남아있는것들 누적주차시간 더해줘야함
    for(auto x : carnumber){
        if(um[x].empty())continue;
        else{
            totaltime[x] += timecalc(um[x], "23:59");
        }
    }

    //이제 누적 주차시간 있으니 요금 계산
    for(auto x: carnumber){
        preresult.push_back({x, feecalc(x, fees[0],fees[1],fees[2],fees[3])});  //(기본 시간, 기본 요금, 단위 시간, 단위 요금) 
    }

    sort(preresult.begin(),preresult.end(),cmp);
    //answer.resize(carnumber.size());

    for(auto x : preresult)answer.push_back(x.second);
    
    return answer;
}

