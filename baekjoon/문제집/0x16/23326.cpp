#include<bits/stdc++.h>
using namespace std;

set<int> chk; // i번째구역이 명소인지 명소이면 1


int main(void){

    int n,q;
    int cur = 1;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        int in;
        cin >> in;
        if(in)chk.insert(i);
    }

    for(int i=0;i<q;i++){
        int input;
        cin >> input;
        if(input == 3){
            if(chk.empty())cout << -1 << '\n';
            auto it = chk.lower_bound(cur);
            if(it != chk.end()){ // cur이후에 명소가있을때
                cout << *it-cur << '\n';
            }       
            else{ //cur이전에 명소가 있을때 그까지의 거리
                cout << (n - cur) + *chk.begin() << '\n';
                 
            }

        }
        else if(input == 2){
            int a;
            cin >> a;
            cur = (cur + a -1)%n +1;
            
        }
        else if(input == 1){
            int x;
            cin >> x;
            if(chk.find(x) != chk.end()){
                chk.erase(x);
            }
            else{
                chk.insert(x);
            }
        }

    }

    return 0;
}