#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    //누적주차시간을 구하는 로직만들고나서 주차요금을 계산한다

    unordered_map<string, int> car; // 차량번호,있었던시간을 매칭
    unordered_map<string,bool> check//차량번호랑 status나타내는

    for(int i=0;i<records.size();i++){
        stringstream iss(records[i]);
        
        string time,car_number,status;
        iss >> time >> car_number >> status;
        
        stoi(time.substr(0,2);
        time.substr()
        if(status=="IN"){
            check[car_number]=true;
        }
        if(status=="OUT"){

            check[car_number]=false;
        }
        if(check[car_number]){

        }


    }

 
    return answer;
}