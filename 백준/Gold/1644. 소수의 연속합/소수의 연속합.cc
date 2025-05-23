#include<bits/stdc++.h>
using namespace std;
int n;
//bool isUnique[4000005];

void uniqueNum(int k, vector<bool>& isUnique) {
    isUnique[1] = false;

    for(int i=2;i*i<=k;i++) {
        for(int j=i*i;j<=k;j+=i) {
            if(isUnique[j])isUnique[j] = false;
            //cout << j << ' ';
        }
    }
}

vector<int> v;
int ans = 0;
int main() {

    
    cin >> n;
    if(n==1) {
        cout << 0;
        return 0;
    }
    //원래 전역변수로 선언해줬는데 초기화가 잘못되었었다!! n=0이어서(전역) 크기가3인 벡터였음.. 
    vector<bool> isUnique(n+5, true);

    uniqueNum(n, isUnique);
    // for(int i=2;i<=n;i++) {
    //     if(isUnique[i] && i == 53) {
    //         cout << isUnique[i] << ' ';
    //     }
    // }

    for(int i=2;i<=n;i++) {
        if(isUnique[i]) {
            v.push_back(i);
            //cout << i << ' ';
        }
    }

    //for(auto z: v)cout << z << ' ';
    int en = 0;
    int tot = v[0];
    for(int st=0;st<v.size();st++) {
        while(en < v.size() && tot < n) {
            en++;
            tot += v[en];
        }
        if(tot == n) {
            //cout << st << ' ' << en << '\n';    
            ans++;
        }
        if(en == v.size())break;
        tot -= v[st];
    }
    
    cout << ans;
    return 0;
}