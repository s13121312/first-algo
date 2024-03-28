#include<bits/stdc++.h>
using namespace std;

string change(int k,int n){
    string tmp;
    if(k==0){
        return "0";
    }
    while (k>0)
    {
        if(k%n>=10 && k%n <=15){
            tmp +='A' + (k%n-10);
        }
        else{
            tmp += to_string(k%n);
        }
        k/=n;
    }
    reverse(tmp.begin(),tmp.end());
    return tmp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    string tmp;
    for(int i=0;i<t*m;i++){ //TODO 범위 고치고
        tmp += change(i,n);
    }

    for(int i=p-1;i<tmp.size();i+=m){
        answer.push_back(tmp[i]);
        if(answer.size()==t){
            break;
        }
    }

    return answer;
}
int main() {
    int n = 8, t = 8, m = 5, p = 3;
    cout << solution(n, t, m, p) << endl;

    return 0;
}