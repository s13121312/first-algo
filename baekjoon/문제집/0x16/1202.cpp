#include<bits/stdc++.h>
using namespace std;

pair<int, int> bosuck[300005]; // 가격 무게
multiset<int> ms;

int main(void){

    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> bosuck[i].second >> bosuck[i].first;
    }
    sort(bosuck,bosuck+n); // 가격기준정렬

    for(int i=0;i<k;i++){
        int a;
        cin >> a;
        ms.insert(a);
    }

    long long ans =0;

    for(int i=n-1;i>=0;i--){
        int m,v; // 무게, 가격
        tie(v,m) = bosuck[i];
        auto it = ms.lower_bound(m);
        if(it == ms.end()) continue;
        ans += v;
        ms.erase(it);
    }

    cout << ans;
    return 0;
}