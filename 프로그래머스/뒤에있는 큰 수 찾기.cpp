//되게 신기한 스택! 다시풀기
#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    stack<int> s;
//자신보다 뒤에 있는 숫자 중에서 자신보다 크면서 가장 가까이 있는 수를 뒷 큰수
    for(int i=numbers.size()-1;i>=0;i--){        
        while (1)
        {
            if(s.empty()){
                answer[i] = -1;
                break;
            }
            if(s.top() > numbers[i]){
                answer[i] = s.top();
                break;
            }
            s.pop(); //stack의 top()이 해당 인덱스 수보다 클 때까지 
                     //pop하면 top()은 자연스레 그 큰 수가 됨
        }
        s.push(numbers[i]);
    }
 
    return answer;
}