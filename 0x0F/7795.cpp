#include<bits/stdc++.h>
using namespace std;

int arr1[20005];
int arr2[20005];
int n,m;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int cnt;
    for(int i=0;i<t;i++){
        cnt=0;

        cin >> n >>m;
        for(int j=0;j<n;j++){
            cin >>arr1[j];
        }
        for(int q=0;q<m;q++){
            cin >>arr2[q];
        }

        sort(arr1,arr1+n);
        sort(arr2,arr2+m);
// A의 크기가 B보다 큰 쌍이 몇 개나 있는지
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(arr1[j]>arr2[k]){
                    cnt++;
                }
                else{
                    break;
                }
            }
        }
        cout << cnt<<'\n';
        
    }


    return 0;
}