#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr1[100005];
int arr2[100005];

unordered_set<int> us1;
unordered_set<int> us2;

int main() {
    // Please write your code here.
    
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr1[i];
        us1.insert(arr1[i]);
    }

    cin >> m;
    for(int i=0;i<m;i++) {
        cin >> arr2[i];
        us2.insert(arr2[i]);
    }

    for(int i=0;i<m;i++) {
        if(us1.find(arr2[i]) != us1.end()) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}