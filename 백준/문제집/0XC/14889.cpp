//다시 풀기
#include<bits/stdc++.h>
using namespace std;

int s[25][25];
int ans = 1e9;
int n;

bool isused[25];



//n과m(6)문제 이용 123 456 이 나왔으면 456 123안 포함안되게

void func(int st, int depth){ // 시작 번호, 깊이

    if(depth == n/2){
        
        int start=0;
        int link =0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(isused[i] == true && isused[j] == true)start += s[i][j];
                if(isused[i] == false && isused[j]==false)link += s[i][j];
            }
        }


        if(abs(start-link) < ans){
            ans = abs(start-link);
        }
        return;
    }


    for(int i=st;i<n;i++){  //i ==n이 되버리면 func(n+1,depth+1)을 돌기때문에 
        isused[i] = true;
        func(i+1,depth+1);
        isused[i]=false;
    }

}

int main(void){

    
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> s[i][j];
        }
    }

    func(1,0);

    cout << ans;

    return 0;
}