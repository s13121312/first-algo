#include<bits/stdc++.h>
using namespace std;

int problemlevel[100005]; //문제 번호 - 난이도
set<int> problemsbylevel[105];//난이도 - 문제번호


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int p, l;
        cin >> p >> l;
        problemlevel[p]=l;

        problemsbylevel[l].insert(p);
    }

    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        string op;
        cin >> op;
        if(op == "recommend"){
            int x;
            cin >> x;
            if(x==1){
                for(int i=100;i>=0;i--){
                    if(problemsbylevel[i].empty())continue;
                    cout << *(prev(problemsbylevel[i].end())) << '\n';
                    break;
                }
                
            }
            if(x == -1){
                for(int i=0;i<=100;i++){
                    if(problemsbylevel[i].empty())continue;
                    cout << *problemsbylevel[i].begin() << '\n';
                    break;
                }
            }
        }
        else if(op == "add"){
            int p,l;
            cin >> p >> l;
            problemlevel[p]=l;

            problemsbylevel[l].insert(p);
        }

        else if(op == "solved"){ //solved
            int p;
            cin >> p;
            problemsbylevel[problemlevel[p]].erase(p);
        }
    }


    return 0;
}