#include <bits/stdc++.h>

using namespace std;

int t,N;
int A[1234];
string s;

void process(){
	for(int i = 0; i < N; ++i) A[i + 1] = s[i] == '1';
	int res = N;
	for(int i = 1; i <= N; ++i){
		if(A[i]){
			res = max(res,2 * i);
			res = max(res,2 * (N - i + 1));
		}
	}
	cout << res << endl;
}
int main(){
	cin >> t;
	for(int i = 1; i <= t; ++i){
		cin >> N;
		cin >> s;
		process();
	}
}