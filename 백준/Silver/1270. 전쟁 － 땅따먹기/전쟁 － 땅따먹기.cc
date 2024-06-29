#include<bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        vector<long long> arr(a);
        unordered_map<long long, long long> um;

        for(int j=0;j<a;j++){
            cin >> arr[j];
            um[arr[j]]++;
        } 
        long long max_el = -1;
        long long max_cnt = 0;
        for(int j=0;j<a;j++){
            if(max_cnt <= um[arr[j]]){
                max_cnt = um[arr[j]];
                max_el = arr[j];
            }
        }
        if(max_el != -1 && max_cnt > a/2){
            cout << max_el<< '\n';
        }
        else{
            cout << "SYJKGW"<<'\n';
        }
    }

    return 0;
}