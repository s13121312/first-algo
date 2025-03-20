#include<bits/stdc++.h>
using namespace std;

int n = 50; 
vector<bool> v(n+1, true);

int main() {


    for(int i=2;i*i<=n;i++) {
        for(int k=i*i;k<=n;k+=i) {
            if(v[k]) {
                v[k] = false;
            }
        }
    }


    for(int i=1;i<=n;i++) {
        if(i%10==0)cout << '\n';
        cout << v[i] << ' ';
    }

    return 0;
}