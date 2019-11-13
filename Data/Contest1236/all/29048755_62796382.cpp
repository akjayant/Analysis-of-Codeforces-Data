#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int F(int x, int y, int n){
	int tmp1 = y * n; 
	int tmp2; 
	if(y % 2 == 0) tmp2 = x + 1; 
	else tmp2 = n - x; 
	return tmp1 + tmp2; 
}
int main(){
	int N; cin >> N; 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << F(i, j, N) << " "; 
		}
		cout << endl; 
	}
}