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
bool read_c() {
	char c = getchar();
	while(c != '0' && c != '1') c = getchar();
	return c - 48;
}
bool mapp[1010];
int main() {
	int t = read();
	while(t--) {
		int n = read(), ans = 0;
		for(int i = 1; i <= n; ++i) mapp[i] = read_c();
		int pos = 0;
		for(int i = 1; i <= n; ++i) {
			if(mapp[i]) pos = max(pos, i);
		}
		ans = max(pos*2, n);
		reverse(mapp+1, mapp+n+1);
		pos = 0;
		for(int i = 1; i <= n; ++i) {
			if(mapp[i]) pos = max(pos, i);
		}
		ans = max(ans, pos*2);
		cout << ans << endl;
	}
	
	return 0;
}