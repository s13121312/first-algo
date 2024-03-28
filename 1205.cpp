#include<bits/stdc++.h>
using namespace std;

int arr[55];
int r[55];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, new_score, p;
    cin >> n >> new_score >> p;
    if(n==0){
        cout << '1';
        return 0;
    }

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    if(arr[n-1]== new_score && p == n){
        cout << "-1";
        return 0;
    }
    else{
        int rank=1;
        for(int i=0;i<n;i++){
            if(new_score<arr[i])rank++;
            else break;
        }
        cout << rank <<'\n';
    }
    return 0;
}