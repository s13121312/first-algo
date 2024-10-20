#include<iostream>

using namespace std;

int calc(int(& arr)[1005], int n){
    int sum = 0;

    for(int i = 2;i<n-2;i++){
        int tmp = 0x7fffffff;
        if(arr[i] > arr[i-1] && arr[i] >arr[i-2] && arr[i] > arr[i+1] && arr[i] > arr[i+2]){
            for(int j = -2;j<=2;j++){
                if(j==0)continue;
                if(tmp > arr[i] - arr[i+j]){
                    tmp = arr[i] - arr[i+j];
                }
            }
        }
        if(tmp == 0x7fffffff)tmp = 0;
        sum += tmp;
    }
    return sum;
}

int main()
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
    
	for(test_case = 1; test_case <= 10; ++test_case)
	{
        int n;
		cin >> n;
        int arr[1005];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }

        cout << "#"<< test_case << ' ' << calc(arr, n) << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}