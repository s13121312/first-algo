#include<bits/stdc++.h>
using namespace std;



int main(void){

    int t;
    cin >> t;

    while (t--)
    {
        int k;
        cin >> k;
        multiset<int> ms;
        for(int i=0;i<k;i++){
            char op;
            int n;
            cin >> op >> n;
            // ‘I n’은 정수 n을 Q에 삽입하는 연산
            //D 1 는 Q에서 최댓값을 삭제하는 연산
            // ‘D -1’는 Q 에서 최솟값을 삭제
            
            if(op == 'I'){
                ms.insert(n);
            }
            if(op == 'D'){
                if(ms.empty())continue;

                if(n == 1){
                    ms.erase(prev(ms.end()));
                }
                if(n == -1){
                    ms.erase(ms.begin());
                }
            }
        }   

        if(ms.empty()){
            cout << "EMPTY" << '\n';
        }
        else{
            cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
        }

    }
    

    return 0;
}