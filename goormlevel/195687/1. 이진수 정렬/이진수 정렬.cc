#include<bits/stdc++.h>
using namespace std;

int n, k;
int arr[500005];
pair<int, int> p[500005];


bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second)return a.first > b.first;
    return a.second > b.second;
}


int ejinsu(int t){
    vector<int> bin;
    //이진수를 만들지말고 그냥 1의개수만 세자.
    int tmp = 0;
    while (t > 0)    
    {
        bin.push_back(t%2);    
        if(t%2 == 1)tmp++;
        t/=2;
    }
    return tmp; 
}



void input(){
    cin >> n >>k;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        
        p[i] = {arr[i], ejinsu(arr[i])}; //숫자랑, 2진수로 변환했을때 1의개수
    }

}

void pro(){

    sort(p,p+n,cmp);
    cout << p[k-1].first;
}

int main(){

    input();
    pro();

    return 0;
}