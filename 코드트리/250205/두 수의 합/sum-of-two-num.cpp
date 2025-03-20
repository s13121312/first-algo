#include <bits/stdc++.h>
using namespace std;

int n, k, arr[100005];
unordered_map<int, int> um;

void input() {
    
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
}

void pro() {

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            um[arr[i]+arr[j]]++;
        }
    }
    cout << um[k];
}

int main() {
    // Please write your code here.
    input();
    pro();
    
    return 0;
}