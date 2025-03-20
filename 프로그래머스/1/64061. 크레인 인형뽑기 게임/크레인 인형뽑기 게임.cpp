#include <bits/stdc++.h>
#include <vector>

using namespace std;
//13m
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    stack<int> s;
    
    for(auto m : moves) {
        m = m-1; //0-index로 하자.
        for(int i=0;i<board.size();i++) {
            if(board[i][m]>0){
                if(s.empty()) {
                    s.push(board[i][m]);
                    board[i][m] = 0;
                } else {
                    if(s.top() == board[i][m]) {
                        board[i][m] = 0;
                        s.pop();
                        answer+=2;
                    } else {
                        s.push(board[i][m]);
                        board[i][m] = 0;
                    }
                }
                break;
            }
        }
        
    }
    
    
    return answer;
}






/*
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;

    for (int i = 0; i < moves.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[j][moves[i] - 1] != 0)
            {
                if (!s.empty() && s.top() == board[j][moves[i] - 1])
                {
                    s.pop();
                    answer += 2;
                    board[j][moves[i]-1]=0;
                    break;
                }
                else
                {
                    s.push(board[j][moves[i] - 1]);
                    board[j][moves[i]-1]=0;
                    break;
                }
            }

            
        }
    }

    return answer;
}
*/