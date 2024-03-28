#include<bits/stdc++.h>
using namespace std;

int answer = 0;
void func(int depth, vector<int> &numbers, int &target, int sum){

    if(depth == numbers.size()){
        if(sum == target){
            answer++;
        }
        return;
    }       

    func(depth+1, numbers, target, sum + numbers[depth]);
    func(depth+1, numbers, target, sum - numbers[depth]);
    
}   


int solution(vector<int> numbers, int target) {
    

    func(0,numbers,target,0);

    return answer;
}