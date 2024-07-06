#include<bits/stdc++.h>
using namespace std;


int arr[11];

int main(void){

    int n;
    cin >> n;
    while (1)
    {
        int a = n % 10;
        arr[a]++;
        if(n/10 ==0){
            break;
        }
        
        n = n/10;
    }
    
    int m = -1;

    for(int i=0;i<10;i++){
        if(i != 6 && i != 9){
            m = max(m, arr[i]);
        }
    }

    cout << max(m, (arr[6]+arr[9]+1)/2);


}