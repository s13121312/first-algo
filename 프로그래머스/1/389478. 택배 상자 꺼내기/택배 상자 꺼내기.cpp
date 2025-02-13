#include <string>
#include <vector>
#include <iostream>

using namespace std;
int arr[105][105];
int height; //행
int row;  //열

int solution(int n, int w, int num) {
    int answer = 0;
    row = w;
    height = n / w;
    if(n % w > 0)height++;
    
    int number = 1;
    int posx;
    int posy;
    for(int i=0;i<height;i++) {
        if(i%2 == 0) {
            for(int j=0;j<w;j++) {
                if(number > n)continue;
                arr[i][j] = number++; 
                if(arr[i][j] == num) {
                    posx = i;
                    posy = j;
                }
            }
        } else {
            for(int j=w-1;j>=0;j--) {
                if(number > n)continue;
                arr[i][j] = number++; 
                if(arr[i][j] == num) {
                    posx = i;
                    posy = j;
                }
            }
            
        }
    }

    while(1) {
        if(arr[posx][posy] <= 0)break;
        posx++;
        answer++;
    }
    
    return answer;
}