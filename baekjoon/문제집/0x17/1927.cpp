//솔직히 구현 이해가안되네어렵다.
#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void push(int x)
{
    heap[++sz] = x; //++sz 는 연산후의값을반환
    int idx = sz;
    while (1)
    {
        int par = idx/2;
        if (heap[idx] >= heap[par])break;
        swap(idx,par);
        idx = par;
    }
}

int top()
{
    return heap[1];
}

void pop()
{

    heap[1] = heap[sz--];
    int idx = 1;
    while (2*idx <= sz)
    {
        int lc = 2*idx; int rc = 2*idx + 1;
        int min_child = lc;
        //오른쪽 자식이 없는 경우를 잘 처리하기 위해서 rc<=sz
        if(rc <= sz && heap[rc] <= heap[lc]){
            min_child = rc;
        }
        if(heap[idx] <= heap[min_child])break;
        swap(heap[idx], heap[min_child]);
        idx = min_child;
    }

}

void test()
{
    push(10);
    push(2);
    push(5);
    push(9);               // {10, 2, 5, 9}
    cout << top() << '\n'; // 2
    pop();                 // {10, 5, 9}
    pop();                 // {10, 9}
    cout << top() << '\n'; // 9
    push(5);
    push(15);              // {10, 9, 5, 15}
    cout << top() << '\n'; // 5
    pop();                 // {10, 9, 15}
    cout << top() << '\n'; // 9
}

int main()
{
    test();
}

