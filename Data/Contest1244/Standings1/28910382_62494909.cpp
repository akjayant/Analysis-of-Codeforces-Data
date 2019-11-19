#pragma GCC optimize("2,Ofast,inline")
#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define pii pair<int, int>
using namespace std;
const int N = 1e6 + 10;

template <typename T> T read(T &x) {
	int f = 0;
	register char c = getchar();
	while (c > '9' || c < '0') f |= (c == '-'), c = getchar();
	for (x = 0; c >= '0' && c <= '9'; c = getchar())
		x = (x << 3) + (x << 1) + (c ^ 48);
	if (f) x = -x;
	return x;
}

int n;
int a[N], b[N], tag[N];
LL k;
char s[N];

void check() {
	for (int i = 2; i <= n; ++i) {
		if (s[i] == s[i - 1]) return;
	}
	for (int i = 1; i <= n; ++i) {
		if (k & 1) {
			putchar('W' + 'B' - s[i]);
		}
		else putchar(s[i]);
	}
	exit(0);
}

int main() {
	read(n); read(k);
	scanf("%s", s + 1);
	if (n % 2 == 0) check();

	int P = 0;

	for (int i = 1; i <= n; ++i) s[i + n] = s[i];
	for (int i = 1; i <= n; ++i) {
		if (s[i] == s[i + 1]) {
			P = i;
			break;
		}
	}
	for (int i = 1; i <= n; ++i) {
		a[i] = (s[i] == 'W') ? 1 : 0;
	}
	for (int i = 1; i <= n; ++i) {
		a[i + n] = a[i];
	}
	for (int i = P; i < P + n; ++i) {
		tag[i] = (a[i] != a[i - 1]) && (a[i] != a[i + 1]);
	}

	// for (int i = 1; i <= n * 2; ++i)
	// 	cout << a[i] << ' ';
	// puts("");
	// cout << P << endl;

	for (int i = 1; i <= n * 2; ++i) b[i] = a[i];

	for (int i = P; i < P + n;) {
		if (tag[i] == 1) {
			int j = i;
			while (tag[j + 1]) ++j;
			// cout << i << ' ' << j << endl;
			// cout << a[i - 1] << ' ' << a[j + 1] << endl;
			if (k & 1) {
				for (int l = i; l <= j; ++l)
					b[l] = a[l] ^ 1;
			}
			int L = i, R = j;
			for (int l = 1; l <= k; ++l) {
				b[L] = a[i - 1];
				b[R] = a[j + 1];
//				cout << L << ' ' << R << endl;
				++L; --R;
				if (L > R) break;
			}
			i = j + 1;
		}
		else ++i;
	}

	
	
	// for (int i = 1; i <= n * 2; ++i)
	// 	cout << b[i] << ' ';
	// puts("");


	for (int i = 1; i <= n; ++i) {
		int pos = (i < P) ? i + n : i;
		putchar(b[pos] ? 'W' : 'B');
	}
	puts("");
	return 0;
}
