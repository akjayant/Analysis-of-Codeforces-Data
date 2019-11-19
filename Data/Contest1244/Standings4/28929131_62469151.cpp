#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define LL long long
#define p (double)(1.0/6.0)
using namespace std;
LL read() {
	LL k = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
		k = k * 10 + c - 48, c = getchar();
	return k * f;
}
int main() {
	int t = read();
	while(t--) {
		int a = read(), b = read(), c = read(), d = read(), k = read();
		int x = (a/c) + (a % c != 0), y = (b/d) + (b % d != 0);
		if(x + y <= k) {
			cout << k - y  << ' ' << y << endl;
		}
		else {
			cout << -1 << endl;
		}
		
	}
	
	return 0;
}