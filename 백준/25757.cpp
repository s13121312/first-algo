#include<bits/stdc++.h>
using namespace std;

map<string,bool> name;

int main(void){

    int n;
    char c;

    cin >> n >> c;
    int ans=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;

        if(!name[str]){ //없던놈이면
            cnt++;
            if(c=='Y'){
                if(cnt ==1){
                    cnt=0;
                    ans++;
                }
            }
            if(c=='F'){
                if(cnt ==2){
                    cnt=0;
                    ans++;
                }
            }
            if(c=='O'){
                if(cnt ==3){
                    cnt=0;
                    ans++;
                }
            }
            name[str] = true;
        }
        else{
            continue;
        }
    }

    cout << ans;

    return 0;
}