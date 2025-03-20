#include <bits/stdc++.h>
using namespace std;

string word[1005];
int n;
string str;
unordered_map<string,int> um;
void input() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> word[i];
        sort(word[i].begin(), word[i].end());
        um[word[i]]++;
    }
}

void pro() {
    int ans = 1;

    for(unordered_map<string, int>::iterator it=um.begin();it!=um.end();it++) {
        ans = max(ans, it -> second);
    }
    cout << ans;

}

int main() {
    // Please write your code here.
    input();
    pro();

    return 0;
}