#include <bits/stdc++.h>
using namespace std;

    // int sum = 0;

    // for (int i = 1; i <= n; i++)
    // {
        
    //     sum = i;
    //     for (int j = i + 1; j <= n-1; j++)
    //     {
    //         if (i == n)
    //         {
    //             answer++;
    //             cout << i << " to " << j <<" 's sum : " <<  sum << '\n';
    //             break;
    //         }
    //         if (sum == n)
    //         {
    //             answer++;
    //             cout <<i << " to " << j <<" 's sum : " <<  sum << '\n';
    //             break;
    //         }

    //         sum += j;
    //     }
    // }

//누적합으로 구해보자
// 자연수 n을 연속한 자연수들로 표현 하는 방법

int a[10005];
int s[10005];

int solution(int n)
{
    int answer = 1; //n자기자신 1개 미리 세어놓음
    
    for(int i=1;i<n;i++){
        int sum=i;
        for(int j=i+1;j<n;j++){
            sum+=j;
            if(sum == n){
                answer++;
            }
            else if(sum > n){
                break;
            }
        }
    }
    
    

    return answer;
}

int main(void)
{
    int n;
    cin >> n;
    cout << solution(n);
}