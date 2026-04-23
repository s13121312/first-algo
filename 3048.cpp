#include<bits/stdc++.h>
using namespace std;
int n1, n2;
string str;

typedef struct {
    int d;
    char c;
}Ant;

int main() {

    cin >> n1 >> n2;

    vector<Ant> v;

    for(int i=0;i<n1;i++) {
        char c;
        cin >> c;
        v.push_back({0, c});
    }
    reverse(v.begin(), v.end());

    for(int i=0;i<n2;i++) {
        char c;
        cin >> c;
        v.push_back({1, c});
    }
    int t;
    cin >> t;

    for(int i=0;i<t;i++) {
        for(int j=0;j<v.size()-1;j++) {
            if(v[j].d != v[j+1].d && v[j].d == 0) {
                Ant tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
                j++;
            }
        }
    }

    for(int i=0;i<v.size();i++) {
        cout << v[i].c;
    }

    return 0;
}