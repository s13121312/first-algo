#include <bits/stdc++.h>

using namespace std;
int m, k;
map<int,int> ttl;  //서버 개수, 적용된 시점

int inserver[25];
void init() {
    for(int i=0;i<=24;i++)inserver[i] = 0;
}
void print() {
    for(int i=0;i<24;i++)cout << inserver[i] << ' ';
}

int solution(vector<int> players, int _m, int _k) {
    int answer = 0;
    m = _m; k=_k;
    init();
    
    int curserver = 0; // 현재 서버 개수
    
    for(int i=0;i<24;i++) {
        //cout << answer << ' ';
        int minimumserver = players[i] / m;
        curserver = inserver[i];
        //cout << curserver << ' ';
        
        if(curserver >= minimumserver) {
            //있는 서버들로 충분할때
            cout << curserver << ' ';
            continue;
        } else {    //curserver < minimumserver
            int plusserver = minimumserver - curserver;
            curserver += plusserver;
            cout << curserver << ' ';
            for(int j=i;j<i+k;j++){
                if(j>=24)continue;
                inserver[j] += plusserver;
            }
            answer+= plusserver;
        }
        
    }
    
    //print();
    
    return answer;
}
