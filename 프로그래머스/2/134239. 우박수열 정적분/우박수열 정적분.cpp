#include <bits/stdc++.h>

using namespace std;
int n;
vector<long long> val;

int calcn(int k) {
    int cur = k;
    int cnt = 0;
    val.push_back(cur);
    while(true) {
        if(cur <= 1) {
            break;
        }
        if(cur % 2 ==0) {
            cur = cur/2;
        } else {
            cur = cur*3+1;
        }
        val.push_back(cur);
        cnt++;
    }
    return cnt;
}

double calcJ(int a, int b) {
    double sum =0;
    int start, end;
    start = a;
    end = n+b;
    
    if(start>end || end<0)return -1.0;
    // cout << start << ' ' << end;
    // cout << ' ';
    for(int i=start;i<end;i++) {
        sum += ((val[i+1]+val[i])/2.0);
    }
    //cout << sum << ' ';
    return sum;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    n = calcn(k);
    //cout << n;
    for(auto v: val)cout << v << ' ';
    cout << val.size() << '\n';
    
    for(auto x: ranges) {
        answer.push_back(calcJ(x[0], x[1]));
    }
    
    return answer;
}