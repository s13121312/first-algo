#include<bits/stdc++.h>
using namespace std;


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    int sum1;
    int sum2;
    cin >> t;
    while (t--)
    {
        sum1=0;
        sum2=0;
        int a, b;
        cin >> a >> b; 
        if(a==1)
        {
            sum1=5000000;
        }
        else if(a>1 && a<=3)
        {
            sum1=3000000;
        }
        else if(a>3 && a<=6)
        {
            sum1 =2000000;
        }
        else if(a>6 && a<=10)
        {
            sum1 =500000;
        }
        else if(a>10 && a<=15)
        {
            sum1 =300000;
        }
        else if(a>15 && a<=21)
        {
            sum1 =100000;
        }
        else{
            sum1=0;
        }
        if(b==1)
        {
            sum2=5120000;
        }
        else if(b>1 && b<=3)
        {
            sum2=2560000;
        }
        else if(b>3 && b<=7)
        {
            sum2 =1280000;
        }
        else if(b>7 && b<=15)
        {
            sum2 +=640000;
        }
        else if(b>15 && b<=31)
        {
            sum2 +=320000;
        }
        else{
            sum2=0;
        }
        cout << sum1+sum2 << '\n';
    }
    

    return 0;
}