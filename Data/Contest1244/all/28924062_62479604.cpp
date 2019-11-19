#include <iostream>
#include <cstdio>
#define N 100005
using namespace std;

typedef long long ll;
ll n, p, w, d;
bool v[N];
int main()
{
	ll i, t;
	cin >> n >> p >> w >> d;
	for (i = p / w; i >= 0; i--) {
		t = (p - w * i) % d;
		if (t == 0 && i + (p - w * i) / d <= n) {
			cout << i << ' ' << (p - w * i) / d << ' ' << n - i - (p - w * i) / d << endl;
			return 0;
		}
		if (v[t]) break;
		v[t] = 1;
	}
	puts("-1");
    return 0;
}