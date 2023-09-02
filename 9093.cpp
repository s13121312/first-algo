#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    cin.ignore(); //clear buffer
    while (t--)
    {
        string str;
        getline(cin,str);
        str+='\n';
        stack<char> S;
        for(char ch: str)
        {
            if(ch==' ' || ch=='\n') //문자열 중에 공백이나 줄바꿈 문자를 만나면
            {
                while (!S.empty()) //스택 S가 차있다면 거꾸로 출력 후하나씩 빼기
                {
                    cout << S.top();
                    S.pop();
                }
                cout << ch; //이걸 안하면 공백이출력이안돼서 붙어서 나옴                    
            }
            else 
            {
                S.push(ch);
            }
        }
    }
    
    return 0;
}