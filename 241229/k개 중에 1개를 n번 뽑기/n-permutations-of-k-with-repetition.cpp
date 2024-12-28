#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> v;

void input(){
    cin >> k >> n;
}


void pro(int cur){
    if(cur == n+1){
        for(auto x: v)cout << x << ' ';
        cout << '\n';
        return;
    }

    for(int i=1;i<=k;i++){
        v.push_back(i);
        pro(cur+1);
        v.pop_back();
    }


}

int main() {
    // 여기에 코드를 작성해주세요.

    input();
    pro(1);

    return 0;
}