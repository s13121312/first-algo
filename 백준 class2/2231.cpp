#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int sum;
    int g = 1000001;

    for (int i = 1; i <= n; i++)
    {
        int current = i;
        sum=0;
        sum += current;
        while (1)
        {         
            int a= current%10;
            sum += a;
            current /= 10;
            if(current==0)
            {
                if(sum==n){
                    g=min(g,i);
                }
                else{
                    break;
                }
                break;
            }
        }
    }
    if(g==1000001){
        cout << '0';
    }
    else{
        cout << g << '\n';
    }
    
    return 0;
}