/*#include<bits/stdc++.h>
using namespace std;

int arr[8] = {6,-8,1,12,8,3,7,-7};

int main(void){

    int pivot = arr[0];
    int l=1, r=7;
    while (1)
    {
        while (l <= r && arr[l]<=pivot)
        {
            l++;
        }
        while (l >= r && arr[r]>pivot)
        {
            r--;
        }
        if(l>r) break;
        swap(arr[l],arr[r]);
    }
    swap(arr[0],arr[r]);

    
    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;

int n =10;
int arr[1000001]={93,27,-81,33,22,11,53,77,153,12};

//pivot기준왼쪽에는 pivot보다작은거 오른쪽에는 pivot보다 큰거로 정렬하고싶다.
void quick_sort(int st, int en){
    if(en-st<=1)return; //수열의 길이가 1 이하이면 함수 종료.
    int pivot = arr[st];
    int l = st+1;
    int r= en-1;
    while (1)
    {
        //l 왼쪽에는 pivot보다 작은거만
        //바로밑의while문을 빠져나온것들은 맞지않는것들(순서를 바꿔야하는것들) 
        while (l<=r && arr[l] <=pivot)
        {
            l++;
        }
        //r 오른쪽에는 pivot보다 큰거만
        while (l<=r && arr[r] >pivot)
        {
            r--;
        }
        if(l>r)break;
        swap(arr[l],arr[r]);
    }
    swap(arr[st],arr[r]);
    quick_sort(st,r);
    quick_sort(r+1,en);
}
int main(void){

    quick_sort(0,n);
    for(int i=0;i<n;i++){
        cout << arr[i]<<' ';
    }
    return 0;
}