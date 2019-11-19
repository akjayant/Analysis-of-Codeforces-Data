#include <bits/stdc++.h>
 
using namespace std;
#define ff first
#define ss second
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx2")
#define int long long
int  md = 1e9 + 7;
int gcd (int a, int b) {
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}
int fol( char a) {
	int x = a -'a';
	return x;
}
main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector < int > a;
	int ans =0;
	for(int i = 2; i * i <= n;i++) {
		if(n%i == 0) {
			a.push_back(i);
			while(n%i == 0) {
				n = n/i;
			}
		}
	}
	if(n != 1) {
		a.push_back(n);
	}
	if(a.size() == 1) {
		cout << a[0];
	} else {
		cout << 1;
	}
}