#include<bits/stdc++.h>
using namespace std;

string func(int n){
    int arr[3] ={};
    
    string tmp;
    
    while(n>0){
        if(n%3==0){
            n=n/3-1;
            tmp += '4';
        }
        if(n%3==1){
            tmp += '1';
            n/=3;
        }
        if(n%3==2){
            tmp += '2';
            n/=3;
        }
        
    }
    reverse(tmp.begin(),tmp.end());
    return tmp;

}


string solution(int n) {
    string answer = "";

    answer= func(n);


    return answer;
}