#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int arr[15];
vector<int> v;
bool isused[12];
bool chk[5];

int ans =0;
void input(){
    cin >> n >> m >>k;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
}

void backtracking(int cur){
    if(cur == n){
        int cnt = 0;
        unordered_map<int,int> um;

        for(int i=0;i<n;i++){
            um[v[i]] += arr[i];
            if(um[v[i]] >=m-1){
                if(chk[v[i]])continue;
                cnt++;
                um[v[i]] = 0;
                chk[v[i]] = true;
            }
        }
        
        ans = max(ans, cnt);
        return;
    }


    for(int i=1;i<=k;i++){
        v.push_back(i);
        backtracking(cur+1);
        v.pop_back();
    }
}


int main() {
    // Please write your code here.
    input();
    backtracking(0);
    cout << ans;

    return 0;
}