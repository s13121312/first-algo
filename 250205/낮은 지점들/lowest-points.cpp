#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> um;
//1000000000 10억

void input() {

    int n;
    cin >> n;
    vector<int> xpos;
    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        
        if(um.find(x) == um.end()){
            xpos.push_back(x);
            um[x] = y;
        } else {
            um[x] = (um[x] > y) ?  y : um[x]; 
        }
    }

    long long sum = 0;
    for(int x : xpos) {
        sum += um[x];
    }
    cout << sum;


}
int main() {
    // Please write your code here.
    input();

    return 0;
}