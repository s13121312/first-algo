#include <bits/stdc++.h>
#include <vector>

using namespace std;
long long sum;
long long sum1 = 0;
long long sum2 = 0;

queue<int> q1;
queue<int> q2;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    int n = queue1.size();
    sum =0;
    for(int i=0;i<queue1.size();i++) {
        sum1 += queue1[i];
        q1.push(queue1[i]);
        sum2 += queue2[i];
        q2.push(queue2[i]);
    }
    
    sum = sum1 + sum2;
    long long half = sum/2;
    int tmp = 0;
    
    if(sum1 == half)return 0;
    
    while(sum1 != half || sum2 != half) {
        tmp++;
        int f1 = q1.front();
        int f2 = q2.front();
        if(sum1 < sum2) {
            q2.pop();
            q1.push(f2);
            sum2-=f2;
            sum1+=f2;
        } else if(sum2 < sum1) {
            q1.pop();
            q2.push(f1);
            sum2+=f1;
            sum1-=f1;
        } else break;
        if(tmp > 3*n) {    //큐1을 큐2로 다옮기고 큐2를(2n개) 또큐1으로 옮기기까지
            tmp = -1;
            break;
        }
        
    }
    answer = tmp;
    return answer;
}