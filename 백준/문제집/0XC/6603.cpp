#include<bits/stdc++.h>
using namespace std;

int k;
int arr[15];
int isused[15];

void func(int depth, int st){

    if(depth == 6){

        for(int i=0;i<6;i++){
            cout << isused[i] << ' ';
        }
        cout << '\n';
        return;
    }


    for(int i=st;i<k;i++){
        isused[depth] = arr[i]; 
        func(depth+1, i+1);
    }


}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (1)
    {
        cin >> k;
        if(k == 0)break;

        for(int i=0;i<k;i++){
            cin >> arr[i];
        }

        func(0, 0);
        cout << '\n';
        fill(arr,arr+k,0);
    }
    

    return 0;
}