#include<bits/stdc++.h>
using namespace std;

int arr[1005][25];

int func(int t){
    int cnt=0;
    int tmp[1005][25];
    
    tmp[t][0] = arr[t][0];
    int max_front = 0;
    for(int i=1;i<20;i++){
        bool check =false;
        tmp[t][i] = arr[t][i];
        for(int j=i-1;j>=0;j--){
            if(tmp[t][i]<tmp[t][j]){
                 //그 중 가장 앞에 있는 때문에
                check = true;
            }
        }
        if(check)swap(min_front, tmp[t][i]);
        cnt++;
    }

    return cnt;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int p;
    cin >> p;
    while (p--)
    {
        int t;
        cin >> t;
        for(int i=0;i<20;i++){
            cin >> arr[t][i];
            
        
        }
    }
    return 0;
}