#include<bits/stdc++.h>
using namespace std;

int num;
bool cmp(string a, string b){
    if(a[num]==b[num]){
        return a < b;
    }
    return a[num] < b[num];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    num = n;
    sort(strings.begin(), strings.end(), cmp);
    answer=strings;
    return answer;
}
