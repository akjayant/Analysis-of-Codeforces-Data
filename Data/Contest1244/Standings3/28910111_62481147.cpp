#include <bits/stdc++.h>
#define int 	long long
#define LL  	long long
using namespace std;
template <typename tn> void read(tn &a){
	tn x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	a = x * f;
}

int P;

void exgcd(int a, int b, int &x, int &y){
	if (!b){ x = 1, y = 0; return; }
	exgcd(b, a % b, y, x), y -= x * (a / b);
}
int gcd(int x, int y){ return y ? gcd(y, x % y) : x;}

signed main(){
	int n, p, A, B;
	read(n), read(p), read(A), read(B);
	int g = gcd(A, B);
	if (p % g){ puts("-1"); return 0; }
	A /= g, B /= g, p /= g, P = p;
	int x, y; exgcd(A, B, x, y);
	x = (x % B + B) % B;
	x = x * (p % B);
	x = (x % B + B) % B;
	y = (p - A * x) / B;
	if (y < 0){ puts("-1"); return 0; }
	if (B < A){
		int k = y / A; y -= k * A, x += k * B;
		LL X = x, Y = y, T = n - X - Y;
		if (x + y <= n) cout << X << ' ' << Y << ' ' << T << '\n';
		else puts("-1");
	} else {
		LL X = x, Y = y, T = n - X - Y;
		if (x + y <= n) cout << X << ' ' << Y << ' ' << T << '\n';
		else puts("-1");
	}
	return 0;
}
