#include <bits/stdc++.h>
using namespace std;

int an, bn;
int a[200005], b[200005];

int main() {
    // Please write your code here.
    cin >> an >> bn;

    set<int> s1;
    set<int> s2;

    for(int i=0;i<an;i++) {
        cin >> a[i];
        s1.insert(a[i]);
    }
    for(int i=0;i<bn;i++) {
        cin >> b[i];
        s2.insert(b[i]);
    }
    
    int tmp = 0;

    for(int i=0;i<an;i++) {
        if(s2.find(a[i]) == s2.end()) {
            tmp++;
        }
    }
    for(int i=0;i<bn;i++) {
        if(s1.find(b[i]) == s1.end()) {
            tmp++;
        }
    }
    cout << tmp;
    
    return 0;
}