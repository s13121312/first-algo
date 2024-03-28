#include<bits/stdc++.h>
using namespace std;

int arr[500005];
int tmp1[500005];
int tmp2[500005];
int tmp3[500005];

int n;
bool cmp(int &a, int &b){
    return a<b;
}

bool cmp2(const pair<int,int>&a, const pair<int,int>&b){
    if(a.second != b.second){
        return a.second > b.second;
    }
    else{ // 빈도수가 같으면
        return a.first < b.first;
    }
}

int func1(){
    sort(tmp1,tmp1+n,cmp);
    double sum =0;
    for(int i=0;i<n;i++){
        sum += tmp1[i];
    }
    double jungsu = sum / n;

    return floor(jungsu+0.5);
}

int func2(){
    sort(tmp2, tmp2 + n, cmp);
    return tmp2[n/2];
}

int func3(){
    map<int, int> m;
    for(int i=0;i<n;i++){
        m[tmp3[i]]++;
    }

    // 원소, 빈도
    vector<pair<int,int>> v(m.begin(),m.end());
    sort(v.begin(), v.end(), cmp2);

    //최빈값이 한개밖에없을때
    if(v[0].second != v[1].second){
        return v[0].first;
    }
    else{
        return v[1].first;
    }
}
int func4(){
    sort(arr,arr+n,cmp);
    return arr[n-1]- arr[0];
}
int main(void){

    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        tmp1[i] = arr[i];
        tmp2[i] = arr[i];
        tmp3[i] = arr[i];
    }

    cout << func1() << '\n' << func2() << '\n' << func3() << '\n' << func4();

    return 0;
}