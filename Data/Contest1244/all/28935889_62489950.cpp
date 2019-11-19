#include <bits/stdc++.h>

using namespace std;

long long x, y;
long long n, p, draw, win;


int main() {
	cin >> n >> p >> win >> draw;
	int cnt = 0;
	for(long long i = p / win; i >= 0; --i) {
		++cnt;
		if((p - i * win) % draw == 0 && i + (p - i * win) / draw <= n) {
			x = i, y = (p - x * win) / draw;
			cout << x << ' ' << y << ' ' << n - x - y << endl;	
			return 0;
		}
		if(cnt > 200000) break;
	}
	puts("-1");
	return 0;
}