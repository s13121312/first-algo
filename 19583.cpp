#include<bits/stdc++.h>
using namespace std;

//입장부터 퇴장까지 모두 확인된 학회원은 전부 몇 명
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer=0;

    //개강총회가 시작한 시간 이전에 대화를 한 적이 있는 학회원의 닉네임
    //개강총회를 시작하자마자 채팅 기록을 남긴 학회원도
    unordered_map<string,int> m_in;

    string s,e,q;
    cin >> s >> e >> q;
    
    int start = 60*stoi(s.substr(0,2))+stoi(s.substr(3,2));
    int end = 60*stoi(e.substr(0,2))+stoi(e.substr(3,2));
    int ends = 60*stoi(q.substr(0,2))+stoi(q.substr(3,2));

    string str;
    
    string time,nickname;
    while (cin >> time >> nickname)
    {
        int t = 60*stoi(time.substr(0,2))+stoi(time.substr(3,2));
        if(t <= start){
            m_in[nickname]=1;
        }
        if(t >= end && t <= ends){
            if(m_in[nickname]==1){
                m_in[nickname]=2;
                answer++;
            }
        }
    }
    
    cout << answer;


    return 0;
}