#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    ll sum = 0;
    for(int i=0;i<queue1.size();i++){
        sum +=queue1[i];
    }
    for(int i=0;i<queue2.size();i++){
        sum +=queue2[i];
    }

    if(sum%2!=0){
        answer=-1;
        return answer;
    }
    else{
        
    }
    return answer;
}