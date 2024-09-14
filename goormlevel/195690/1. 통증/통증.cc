#include<bits/stdc++.h>
using namespace std;

int n;

int main(){

    //1,7,14
    cin >> n;
    int ans = 0;
    while (n>0)
    {
        if(n / 14 > 0){
            ans += (n/14);
            n = n- 14*(n/14);
            
            
        } 
        else if(n /7 > 0){
            ans += (n/7);
            n = n - 7*(n/7);
            
        }else{
            n -= 1;
            ans++;
        }
    }
    
    cout << ans;

    return 0;
}