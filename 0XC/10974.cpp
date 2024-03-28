#include<bits/stdc++.h>
using namespace std;

int n;
int arr[10];
bool isused[10];

void func(int depth){

    if(depth == n){
        for(int i=0;i<n;i++){
            cout << arr[i] << ' '; 
        }
        cout << '\n';
        return;
    }

    for(int i=0;i<n;i++){
        if(isused[i])continue;
        isused[i] = true;
        arr[depth] = i+1;
        func(depth+1);
        isused[i] = false;        
    }
    
}

int main(void){
   
    cin >> n;

    func(0);

    return 0;
}