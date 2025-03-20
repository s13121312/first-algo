#include<bits/stdc++.h>
using namespace std;

int n;
int s[15];//내구도
int w[15];//무게
int ans=0;
int cnt=0;
// 계란으로 계란을 치게 되면 각 계란의 내구도는 상대 계란의 무게만큼 깎이게 된다
void func(int depth){ //cur번째 계란으로 다른걸 깰 차례
    
    if(depth==n){
        ans= max(ans,cnt);
        return;
    }
//손에 든 계란이 깨졌거나 깨지지 않은 다른 계란이 없으면 == s[depth]<=0 || 손에든거 빼고 다깨졌으면
    if(s[depth]<=0 || cnt == n-1) 
    {
        func(depth+1);
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(i == depth || s[depth]<=0) continue; //자기자신은 넘어가고 깨진거는 넘어감
        s[depth] -= w[i];
        s[i] -= w[depth];
        if(s[depth]<=0)cnt++;
        if(s[i]<=0)cnt++;
        
        func(depth+1);

        if(s[depth]<=0)cnt--; //예시로 보면 이코드바로이해됨
        if(s[i]<=0)cnt--;
        s[i] += w[depth];
        s[depth] += w[i];
    }
   
}
int main(void){
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> s[i] >> w[i];
    }

    func(0);
    cout << ans;
}