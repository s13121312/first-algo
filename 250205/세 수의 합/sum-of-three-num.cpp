#include <bits/stdc++.h>
using namespace std;

int n , k, arr[1005];

void input() {

    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
}
//1000,000,000
void pro() {

    int ans = 0;
    for(int i=0;i<n-2;i++) {
        int diff = k-arr[i];
        //나머지 두개의 합이 diff인지    i< j < k(diff-arr[j])를 만족하게.
        unordered_map<int, int> um;
        for(int j=i+1;j<n;j++) {
            ans += um[diff-arr[j]];
            um[arr[j]]++;
        }
        
    }

    cout << ans;
}

int main() {
    // Please write your code here.
    input();
    pro();


    return 0;
}