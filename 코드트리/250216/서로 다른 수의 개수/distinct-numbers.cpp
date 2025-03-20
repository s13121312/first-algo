#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100005];

int main() {
    // Please write your code here.
    unordered_map<int,int> um;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        //us.insert(arr[i]);
        um[arr[i]]++;
    }

    int tmp = 0;

    for(unordered_map<int,int>::iterator it=um.begin();it!=um.end();it++) {
        tmp++;
    }
    cout << tmp;


    return 0;
}