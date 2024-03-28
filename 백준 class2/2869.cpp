#include<bits/stdc++.h>
using namespace std;


int main(void)
{
    int a,b,v;
    cin >> a >> b >> v;
    
    int answer =0;
    int height=0;
    
    for(int i=0;i<1000000000;i++)
    {
        answer++;
        height +=a;
        if(height>=v)
        {
            break;
        }
        height -=b;
        
    }
    cout << answer;
    


    return 0;
}