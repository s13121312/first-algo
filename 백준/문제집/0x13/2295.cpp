#include<bits/stdc++.h>
using namespace std;

int u[1005];
int two[1000005];

int main(void){

    int n; 
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> u[i];
    }
    int k=0;
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            two[k++] = u[i]+u[j];
        }
    }

    sort(two,two+n*n);
    vector<int> ans;

    for(int i=n-1;i>=1;i--){
        for(int j=i-1;j>=0;j--){
            if(binary_search(two,two+n*n,u[i]-u[j])){
                cout << u[i];
                return 0;
            }
        }
    }
    

    return 0;
}