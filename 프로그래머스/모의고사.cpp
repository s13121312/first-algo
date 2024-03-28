#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int arr1[5]={1,2,3,4,5};
    int arr2[8] = {2,1,2,3,2,4,2,5};
    int arr3[10] = {3,3,1,1,2,2,4,4,5,5};
    
    int sc1=0;
    int sc2=0;
    int sc3=0;

    for(int i=0;i<answers.size();i++){
        if(answers[i]==arr1[i%5]){
            sc1++;
        }
        if(answers[i]==arr2[i%8]){
            sc2++;
        }
        if(answers[i]==arr3[i%10]){
            sc3++;
        }
    }
    int k = max(sc1,sc2);
    k=max(k,sc3);
    if(k==sc1){
        answer.push_back(1);
    }
    if(k==sc2){
        answer.push_back(2);
    }
    if(k==sc3){
        answer.push_back(3);
    }
    sort(answer.begin(),answer.end());
    return answer;
}