#include<bits/stdc++.h>
using namespace std;

pair<int, int> v[100005]; //[end time ,start time]

//끝나는 시간이 빠른 순으로, 
//끝나는 시간이 같다면 시작하는 시간이 빠른 순으로 정렬

int main(void){

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> v[i].second >> v[i].first;
    }
    sort(v,v+n);

    for(int i=0;i<n-1;i++){
        if(v[i].first<=v[i+1].second)
    }
    

    return 0;
}