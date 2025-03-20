#include<bits/stdc++.h>
using namespace std;

int n;
unordered_map<string, int> um;
int main(void) {

    cin >> n;

    for(int i=0;i<n;i++) {
        string str;
        cin >> str;
        um[str]++;
    }
    string an;
    int ans = 0;
    for(unordered_map<string,int>::iterator it = um.begin();it!=um.end();it++) {
        if(ans <= it-> second) {
            if(ans == it->second) {
                an = an < it -> first ? an : it ->first;
            } else {
                an = it->first;
            }

            ans = it -> second;
        }
    }

    cout << an;
    
    return 0;
}


/*int main(void) {
    
    getline(cin, a);
    getline(cin, b);

    int idx = 0;
    int tmp = 0;

    while(1) {
        if(a.find(b, idx) == string::npos)break;
        tmp++;
        idx = a.find(b, idx + b.size());
        cout << idx << ' ';
        
    }
    
    cout << '\n' << tmp;

    return 0;
}*/