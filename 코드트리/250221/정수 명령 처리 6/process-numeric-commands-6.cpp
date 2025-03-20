#include <iostream>
#include<queue>
using namespace std;
priority_queue<int> pq;

int n;

int main() {
    // Please write your code here.
    cin >> n;
    while(n--) {
        string str;
        cin >> str;
        if(str == "push") {
            int a;
            cin >> a;
            pq.push(a);
        } else if(str == "size") {
            cout << pq.size() << '\n';
        } else if(str == "empty") {
            if(pq.empty())cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if(str == "pop") {
            cout << pq.top() << '\n';
            pq.pop();
        } else if(str == "top") {
            cout << pq.top() << '\n';
        }
    }



    return 0;
}