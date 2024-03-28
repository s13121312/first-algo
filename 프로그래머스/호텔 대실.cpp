#include<bits/stdc++.h>
using namespace std;

int TimeToint(string input){

    int h = stoi(input.substr(0,2));
    int m = stoi(input.substr(3,2));
    int result = h*60+m;
    return result;
}

bool cmp(const pair<int,int>&a, const pair<int,int>&b){

    if(a.second != b.second){
        return a.second>b.second;
    }
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<pair<int,int>> hours;
    vector<vector<pair<int,int>>> rooms;

    for(int i=0;i<book_time.size();i++){
        
        int st = TimeToint(book_time[i][0]);
        int en = TimeToint(book_time[i][1]);
        hours[i] = make_pair(st,en);
    }

    stable_sort(hours.begin(),hours.end(),cmp);

    for(int i=0;i<hours.size();i++){
        bool bsuccess = false;
        for(int j=0;j<rooms[i].size();j++){
            if(rooms[j].back().first - hours[i].second >= 10){
                bsuccess = true;
                rooms[j].push_back(hours[i]);
                break;
            }
        }
        if(!bsuccess){
            vector<pair<int,int>> room;
            room.push_back(hours[i]);
            rooms.push_back(room);
        }
    }

    answer=rooms.size();

    return answer;
}