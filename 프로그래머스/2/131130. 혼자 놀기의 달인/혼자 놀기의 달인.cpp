#include<bits/stdc++.h>
using namespace std;
bool vis[100] = {false};

int findnxt(int c, vector<int> cards){

    //
    int cur = c;   //cur이 1이면은 nxt는 cards[0]을 접근해야함. 인덱스 매칭 문제가 있음.
    vector<int> tmp;


    while (!vis[cur])
    {   
        tmp.push_back(cur); //{1,2}일때 이미들어간애
        vis[cur] = true;
        cur = cards[cur] - 1; //0-index로 사용하기위해서
    }
    
    return tmp.size();
}

int solution(vector<int> cards) {
    int answer = 0;

    vector<int> group;

    for(int i=0;i<cards.size();i++){
        if(!vis[i]){
            int tmp = findnxt(i, cards);
            group.push_back(tmp);
            cout << tmp <<'\n';
        }
    }


    if(group.size() == 1)return 0;
    for(int i=0;i<group.size()-1;i++){
        for(int j=i+1;j<group.size();j++){
            answer = max(answer, group[i] * group[j]);
        }
    }


    return answer;
}

