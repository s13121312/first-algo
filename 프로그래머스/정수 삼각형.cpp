//다시 풀기
#include<bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int d[505];

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    d[1] = triangle[0][1];
    for(int i=2;i<=triangle.size();i++){
        for(int j=2;j<=triangle[i].size();j++){
            d[i]=max(d[i-1]+triangle[i][j+1],d[i-1]+triangle[i+1][j+1]);
        }
    }

    return d[triangle.size()];
}