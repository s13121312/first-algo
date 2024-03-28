#include<bits/stdc++.h>
using namespace std;

void hanoi(int a, int b, int n){

}
//a에서 b로
void move(vector<vector<int>> &answer, int a, int b, int n) {
    if(n==1){
        answer.push_back({a,b});
        return;
    }
    move(answer, a, 6-a-b, n-1);
    move(answer, a, b, 1);
    move(answer, 6-a-b, b, n-1);

}

vector<vector<int>> solution(vector<vector<int>> &answer, int a, int b, int n) {
    vector<vector<int>> answer;

    move(answer, 1, 3, n);

    return answer;
}