#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    map<string, bool> p;
    for (int i = 0; i < phone_book.size(); i++)
    {
        p[phone_book[i]]=true;
    }

    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        string idx = phone_book[i]; // 기준
        if(phone_book[i+1].substr(0,idx.size())==idx){
            answer=false;
            return answer;
        }
        // for (int j = i + 1; j < phone_book.size(); j++)
        // {
        //     if (phone_book[j].substr(0,idx.size())==idx)
        //     {
        //         answer=false;
        //         return answer;
        //     }
        // }
    }

    return answer;
}