#include <bits/stdc++.h>
using namespace std;
//곱한 수 % 10 == 0이라면, number /= 10 , count++
//이런식으로 최대한 뒤에 0의 개수를 구하면서 정답을 구하려고 했다.
//중요한건 이 방법이 작은 수 (대략 60이었나?)까지 먹히고 input으로 100을 넣었을 때 먹히지 않았다.
//input을 소인수분해로 2x5의 연산이 얼마나 일어나는지 보면 된다.
//2 * 5 를 단순히 세는게아니라 5의 개수를 세면됨(2는 굉장히 많이 나옴)


int main(void)
{
    int n, count=0;
    cin >> n;
    count += n/5;
    count += n/25;
    count += n/125;
    
    cout << count;
    return 0;
}