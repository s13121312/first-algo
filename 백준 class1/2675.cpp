#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T,R;
    cin >>T;
    string S;
    for(int i=0;i<T;i++)
    {
        
        cin >> R;
        cin >> S;
        for(int j=0;j<S.length();j++)
        {
            for(int k=0;k<R;k++)//R이 배열도아닌데 값이 저장이되있나?
            {
                //어떻게 한글자 한글자씩 반복이되나
                cout << S[j];
            }
        }
        cout << "\n";
    }
    

    return 0;
}