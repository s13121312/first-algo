#include<bits/stdc++.h>
using namespace std;

int arr[10001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int in;
        cin >> in;
        arr[in] += 1;
    }


    for(int i=0;i<10001;i++){
        for(int j=0;j<arr[i];j++){
            cout << i << '\n';
        }
        
    }

    return 0;
}