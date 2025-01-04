#include <iostream>
using namespace std;

string input;
int n;
string giho = "";
long long ans = 0;

void backtracking(int idx, long long cur){

    if(idx == giho.size()){
        ans = max(ans, cur);
        return;
    }


    for(int i=1;i<=4;i++){
        if(giho[idx] == '+'){
            backtracking(idx+1, cur+i);
        } else if(giho[idx] == '-'){
            backtracking(idx+1, cur-i);
        } else if(giho[idx] == '*'){
            backtracking(idx+1, cur*i);
        }
    }

}


int main() {
    // Please write your code here.

    cin >> input;
    
    n = input.size();
    for(int i=0;i<n;i++){
        if(input[i] == '-' || input[i] == '+' || input[i] == '*'){
            giho += input[i];
        }
    }
    for(int i=1;i<=4;i++){
        backtracking(0,i);
    }

    cout << ans;

    return 0;
}