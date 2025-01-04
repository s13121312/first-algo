#include <bits/stdc++.h>
using namespace std;

string input;
int n;
string giho = "";
int ans = -0x7fffffff;
vector<char> alphabet;
//a, b, c, d, e, f
vector<int> af_arr;

//알파벳부터 정하고 계산을 해보자.
void backtracking(int cur){
    if(cur == 6){
        //계산하면 될듯
        int tmp = af_arr[alphabet[0] - 'a'];
        for(int i=0;i<giho.size();i++){
            if(giho[i] == '+'){ 
                tmp += af_arr[alphabet[i+1]- 'a'];
            } else if(giho[i] == '-'){
                tmp -= af_arr[alphabet[i+1] -'a'];
            } else if(giho[i] == '*'){
                tmp *= af_arr[alphabet[i+1] -'a'];
            }
        }
        if(ans <tmp){
            ans = tmp;
            // for(int i=0;i<6;i++){
            //     cout << af_arr[i] << ' ';
            // }
            // cout << '\n';
        }
        return;
    }
    for(int i=1;i<=4;i++){
        af_arr.push_back(i);
        backtracking(cur+1);
        af_arr.pop_back();
    }

}


int main() {
    // Please write your code here.

    cin >> input;
    
    n = input.size();

    for(int i=0;i<n;i++){
        if(input[i] == '-' || input[i] == '+' || input[i] == '*'){
            giho += input[i];
        } else if('a' <= input[i] && input[i] <= 'f'){
            alphabet.push_back(input[i]);
        }
    }

    backtracking(0);

    cout << ans;
    
    return 0;
}