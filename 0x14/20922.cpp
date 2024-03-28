#include<bits/stdc++.h>
using namespace std;

int arr[200005];
unordered_map<int, int> m;
int cnt[200005];
int main(void){

    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int len = 0;
    
    int en = 0;

    for(int st=0;st<n;st++){
        while (en < n && cnt[arr[en]] < k)
        {
            cnt[arr[en]]++;
            en++;                      
        }

        len = max(len, en -st);
        if(en == n) break;
        cnt[arr[st]]--;
    }

    cout << len;
    return 0;
}


