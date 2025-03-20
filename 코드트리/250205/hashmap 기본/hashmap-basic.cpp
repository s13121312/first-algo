#include <iostream>
#include<unordered_map>
#include<string.h>
using namespace std;

int n;
unordered_map<int, int> um;
void add(int k, int v);
void remove(int a);
void find(int a);

void input() {
    cin >> n;
    for(int i=0;i<n;i++) {
        string word;
        cin >> word;
        if(word == "add") {
            int k,v;
            cin >> k >> v;
            add(k, v);
        } else if(word == "remove") {
            int a;
            cin >> a;
            remove(a);
        } else if(word == "find") {
            int a;
            cin >> a;
            find(a);
        }
    }
}

void add(int k, int v) {
    um[k] = v;
}

void remove(int a) {
    um.erase(a);
}

void find(int a) {
    if(um.find(a) != um.end()) {
        cout << um[a] << '\n';
    } else {
        cout << "None" << '\n';
    }
}

int main() {
    // Please write your code here.
    input();
    return 0;
}