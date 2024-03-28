//다시 풀기
#include<bits/stdc++.h>

using namespace std;


bool cmp(int &a, int &b){
    return a > b;
}
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<int> count(10000005);
       

    for(int i=0;i<tangerine.size();i++){
        count[tangerine[i]]++;
    }

    sort(count.begin(),count.end(),cmp);

    for(int i=0;i<count.size();i++){
        if(count[i]<k){
            answer++;
            k -= count[i];
        }else{
            answer++;
            break;
        }
    }

    return answer;
}