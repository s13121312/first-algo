#include<bits/stdc++.h>

using namespace std;

char arr[4] = {'1', 'I', 'l', '|'};
int n;
unordered_map<char, int> um;
string line;

void input(){
	getline(cin, line);
	
}

void pro(){
	n = line.size();
	//cout << n << '\n';
	for(int i=0;i<n;i++){
			um[line[i]]++;
    }
	
	for(int i=0;i<4;i++){
        cout << um[arr[i]] << '\n';
    }

}
int main() {
    
    input();
    pro();


	return 0;
}