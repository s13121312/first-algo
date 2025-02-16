#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr1[100005],arr2[100005];

int main() {
    // Please write your code here.

    cin >> n;
    set<int> s1;
    set<int> s2;

    
    for(int i=0;i<n;i++) {
        cin >> arr1[i];
        s1.insert(arr1[i]);
    }

    cin >> m;

    for(int i=0;i<m;i++) {
        cin >> arr2[i];
        s2.insert(arr2[i]);
    }

    for(int i=0;i<m;i++) {
        if(s1.find(arr2[i]) != s1.end())cout << 1 << ' ';
        else cout << 0 << ' ';
    }

    return 0;
}