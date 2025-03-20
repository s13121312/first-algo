#include<bits/stdc++.h>
using namespace std;

vector<int> a,b;

int main(void){

    int n_a,n_b;
    cin >> n_a >> n_b;

    int num;
    for(int i=0;i<n_a;i++){
        cin >> num;
        a.push_back(num);
    }

    for(int i=0;i<n_b;i++){
        cin >> num;
        b.push_back(num);
    }   

    //집합 A에는 속하면서 집합 B에는 속하지 않는 모든 원소를 구하는
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    bool check =false;
    int cnt =0;
    vector<int> ans;
    
    for(int i=0;i<n_a;i++){
        if(binary_search(b.begin(),b.end(),a[i])){
            continue;    
        }
        ans.push_back(a[i]);
    }
    
    cout<< ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout << ans[i]<< ' ';
    }

    return 0;
}