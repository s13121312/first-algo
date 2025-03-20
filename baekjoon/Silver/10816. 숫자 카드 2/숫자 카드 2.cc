#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> um;

int main(void){

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int c;
        cin >> c;
        um[c]++;
    }

    int m;
    cin >> m;

    vector<int> result;
    for(int i=0;i<m;i++){
        int c;
        cin >> c;
        result.push_back(um[c]);
    }

    for(int i=0;i<m;i++){
        cout << result[i] << ' ';
    }
    return 0;
}