#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    int wsmall = (wallet[0] >wallet[1]) ? wallet[1] : wallet[0];
    int wbig = (wallet[0] >wallet[1]) ? wallet[0] : wallet[1];
    
    int small = (bill[0] >bill[1]) ? bill[1] : bill[0];
    int big = (bill[0] >bill[1]) ? bill[0] : bill[1];
    
    while(small> wsmall || big> wbig) {
        big /= 2;
        answer++;
        
        if(big < small) {
            int tmp = small;
            small = big;
            big = tmp;
        }
        //cout << big << ' ' << small<< '\n';
    }
    return answer;
}