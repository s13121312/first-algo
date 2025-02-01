#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    string a;
    cin >> n;
    cin >> a;

    int cnt = 0;

    while (a.size() > 1)
    {
        string tmp = a;
        int tmpsum = 0;
        for(char c : tmp){
            tmpsum += c - '0';
        }
        string k = to_string(tmpsum);
        cnt++;
        a = k;
    }
    cout << cnt << ' ' << a;


    return 0;
}