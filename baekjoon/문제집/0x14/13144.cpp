#include<bits/stdc++.h>
using namespace std;

int arr[100005];
bool cnt[100005];

int main(void){

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int ans = 0;
    int en = 0;

    for(int st=0;st<n;st++){
        while (en<n)
        {
            if(cnt[arr[en]])break;
            cnt[arr[en]] = 1;
            en++;
        }
        // 있으면 안됨 if(en == n) break;
        ans += (en-st); // en-st의 의미는 1,2,3,4,5라는 수열일때 5개를 만들수있음
        cnt[arr[st]] = 0;
    }

    cout << ans;
    return 0;
}