#include<bits/stdc++.h>
using namespace std;

class cmp
{
public:
    bool operator() (int a, int b){
        if(abs(a) != abs(b))return abs(a) > abs(b);
        return a > 0 && b<0; //기본priority_queue가 최대힙이니까 
    }
};



priority_queue<int, vector<int>, cmp> pq;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;

        if(x != 0){
            pq.push(x);
        }
        else{
        //x가 0이라면 배열에서 절댓값이 가장 작은 값을 출력하고 
        //그 값을 배열에서 제거

            if(pq.empty()) cout << '0' << '\n';
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }



    return 0;
}