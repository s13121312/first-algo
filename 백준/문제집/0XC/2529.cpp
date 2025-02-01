#include<bits/stdc++.h>
using namespace std;

char duengho[10];
bool isused[10];
int n;
vector<string> v;

void func(int depth, string num){

    if(depth == n+1){
        for(int i=0;i<n;i++){ // 등호 입력받은거랑 맞는지 확인
            
            
            if(duengho[i] == '<'){
                if(num[i] < num[i+1])continue;
                else{
                    return;
                }
            }
            if(duengho[i] == '>'){
                if(num[i] > num[i+1])continue;
                else{
                    return;
                }
            }
            
        }
        v.push_back(num);
        return;
    }


    for(int i=0;i<=9;i++){
        if(isused[i])continue;
        isused[i]=true;

        func(depth+1, num + to_string(i));
        isused[i]=false;
    }   
}


int main(void){

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> duengho[i];
    }

    func(0, "");
    
    cout << v[v.size()-1] << '\n' << v[0];
    return 0;
}