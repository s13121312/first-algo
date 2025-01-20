#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> answer;
bool visited[15];

void input(){
    cin >> n >> m;
}

//
void pro(int depth, int last_num){
    if(depth == m){
        for(auto x: answer){
            cout<< x << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=depth+1;i<=n;i++){
        if(i > last_num){
            answer.push_back(i);
            pro(depth+1, i);
            answer.pop_back();
        }
    }
}

int main() {
    // Please write your code here.

    input();
    pro(0,0);


    return 0;
}