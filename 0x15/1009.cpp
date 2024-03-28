#include<bits/stdc++.h>
using namespace std;

unordered_set<string> s;

bool cmp(string &a , string & b){
    return a > b;
}
int main(void){

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string a, b;
        cin >> a >> b;
        if(b == "enter"){
            s.insert(a);
        }
        if(b == "leave"){
            s.erase(a);
        }
    }

    vector<string> v(s.begin(),s.end());
    sort(v.begin(),v.end(),cmp);

    for(auto z : v){
        cout << z << '\n';
    }
}