#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int gnum = 1;
    while(1) {
        int n;
        cin >> n;
        if(n == 0)break;
        string name[22];
        bool nasty[22][22]= {0,};
        for(int i=0;i<n;i++) {   
            string str;
            cin >> name[i]; 
            for(int j=1;j<n;j++) {
                char s;
                cin >> s;
                if(s == 'N')nasty[i][j] = true;
            }
        }

        bool chk = false;
        cout << "Group " << gnum++ << '\n';
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(nasty[i][j]) {
                    chk = true;
                    string to = name[i];
                    int idx = (i-j >= 0) ? i-j :i-j+n;
                    cout << i << ' ' << j << '\n'; 
                    string w = name[idx];
                    cout << w << " was nasty about " << to << '\n';
                }
            }
        }
        if(!chk) {
            cout << "Nobody was nasty" << '\n\n';
        }else cout << '\n';
    }

    return 0;
}