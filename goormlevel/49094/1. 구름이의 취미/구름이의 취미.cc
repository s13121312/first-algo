#include <bits/stdc++.h>
using namespace std;
#define NM 1000000007

long long n;
long long sum = 0;

void input(){
	cin >> n;
	
}

void pro(){
	
	sum = (n*(n+1)/2) % NM; //공식
	sum = sum*sum % NM;
	cout <<sum ;
}

int main() {
	
	input();
	pro();
	
	return 0;
}