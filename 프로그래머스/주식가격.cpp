//다시해야함
#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int tmp=0;
    for(int i=0;i<prices.size();i++){
        tmp=0;
        for(int j=i+1;j<prices.size();j++){
            if(prices[i] <= prices[j]){
                tmp++;
            }
            else{
                answer.push_back(tmp);
            }
        } 
    }
    return answer;
}