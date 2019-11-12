#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<map> 
#include<set> 
#include<cmath> 
#include<queue> 


using namespace std;

#define int long long

const int mod = 1e9 + 7;

int n, m;

int bs(int a, int b) {
	if (b == 0) {
		return 1;
	}
	if (b % 2 == 0) {
		int t = bs(a, b / 2);
		return (t * t) % mod;
	}
	else {
		int t = bs(a, b - 1);
		return (t * a) % mod;
	}
}

signed main() {
	cin >> n >> m;
	int onepres = bs(2, m);
	onepres = (onepres + mod - 1) % mod;
	cout << bs(onepres, n);
}