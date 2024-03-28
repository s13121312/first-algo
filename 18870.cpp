#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> tmp;

int num[1000005];

int main(void){

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    vector<int> cv(arr);
    sort(cv.begin(), cv.end());

    cv.erase(unique(cv.begin(),cv.end()));//중복 제거

    /*int k=0;
    map<int,int> m;
    for(int i=0;i<n;i++){
        if(m.find(cv[i]) != m.end())continue;
        m.insert({cv[i],k++});
    }
    for(int i=0;i<n;i++){
        cout << m[arr[i]] << ' ';
    }*/

    for(int i=0;i<n;i++){
        auto it = lower_bound(cv.begin(),cv.end(),arr[i]);

        cout << it-cv.begin() << ' ';
    }


    return 0;
}

