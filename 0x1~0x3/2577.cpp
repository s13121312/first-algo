#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int number[11]={};
    int A,B,C;
    cin >> A >> B >> C;

    int calc=A*B*C;

    while(calc>0)
    {
        number[calc%10]++;
        calc /= 10; 
       
    }
    
    for(int i=0;i<10;i++)
    {
        cout << number[i];
        cout <<"\n";
    }
    return 0;
}