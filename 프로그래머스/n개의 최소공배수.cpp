#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int solution(vector<int> arr)
{
    int answer = 0;
    int tmp = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        tmp = lcm(tmp,arr[i]);
    }
    answer=tmp;
    return answer;
}

int main(void){

    vector<int> arr = {2,6,8,14};
    cout << solution(arr);
    


    return 0;
}