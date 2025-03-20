#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n;
ll m;
ll arr[10005];

void input(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    cin >> m;
}

bool determination(int money){

    ll sum = 0;
    for(int i=1;i<=n;i++){
        if(arr[i]>=money)sum += money;
        else{
            sum += arr[i];
        }
    }

    return sum <= m; 
}

void pro(){

    ll l=0, r = 0, ans = 0;
    //모든 요청이 배정될 수 있는 경우에는 요청한 금액을 그대로 배정한다. 이 조건으로 
    //두번째 예제가 100이나오는것.
    for(int i=1;i<=n;i++){
        r = max(r, arr[i]);
    }
    while (l<=r)
    {
        ll mid = (l+r)/2;
        if(determination(mid)){
            l = mid+1;
            ans = mid;
        }else{
            r = mid-1;
        }
    }

    cout << ans;

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    input();
    pro();

    return 0;
}