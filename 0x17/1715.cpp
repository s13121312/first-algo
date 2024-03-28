//이해가안되네유
#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main(void){

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int c;
        cin >> c;
        pq.push(c);
    }

    int hap = 0;
    while (pq.size() > 1)
    {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        hap += (a+b);
        pq.push(a+b);
    }
    cout << hap;



    return 0;
}