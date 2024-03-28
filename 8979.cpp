#include<bits/stdc++.h>
using namespace std;

typedef struct medal
{
    int g;
    int s;
    int b;
    int r;
}m;

int arr[1005][4];
vector<pair<int,m>> v(1005);

int n,k;
bool cmp(const pair<int, m> &p1, const pair<int, m> &p2){
    if(p1.second.g == p2.second.g){
        if(p1.second.s == p2.second.s){
            if(p1.second.b != p2.second.b){
                return p1.second.b > p2.second.b;
            }
            if(p1.second.b == p2.second.b){
                //같으면은 그냥k번째를 리턴 포인트!
                return p1.first == k;
            }
        }
        return p1.second.s > p2.second.s;
    }
    return p1.second.g > p2.second.g;
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k; // k국가의 등수를 알고싶음.
    int n1,n2,n3,n4;

    for(int i=0;i<n;i++){
        cin >> n1 >> n2 >> n3 >> n4;

        v[i].first = n1;
        v[i].second.g = n2;
        v[i].second.s = n3;
        v[i].second.b = n4;
    }

    sort(v.begin(),v.end(),cmp);

    int rank=1;

    for (int i = 0; i < v.size(); i++)
    {
        v[i].second.r = rank;
        rank++;
    }
    for(int i=0;i<n;i++){
        if(v[i].second.g == v[i-1].second.g && v[i].second.s == v[i-1].second.s && v[i].second.b == v[i-1].second.b){
            v[i].second.r = v[i-1].second.r;
        }
    }
    for(int i=0;i<n;i++){
        if(v[i].first == k){
            cout << v[i].second.r;
            break;
        }
    }

    // // 금, 은, 동이 같을 때 K번째 나라가 제일 앞에 오도록 정렬해놨기에!
    // for(int i=0;i<n;i++){
    //     if(v[i].first == k){
    //         cout << i+1;
    //         break;
    //     }
    // }
    
    
    return 0;
}