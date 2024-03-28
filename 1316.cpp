#include <bits/stdc++.h>
using namespace std;

int n;

bool func(string s)
{

    string tmp[105];
    bool check = true;
    if(s.length()==1){
        return true;
    }
    for (int j = s.length() - 1; j >= 1; j--)
    {
        tmp->push_back(s[j]);
        
        if (s[j] != s[j - 1])
        {
             for(int k=0;k<tmp->size();k++){
                if(s[j-1]==tmp->at(k)){
                    check=false;
                    return false;
                }
             }
        }
    }
    if(check){
        return true;
    }
}

int main(void)
{

    
    int answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if(func(str)){
            answer++;
        }
    }

    cout << answer;
    return 0;
}