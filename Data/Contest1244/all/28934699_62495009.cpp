#include<algorithm>
#include <cstdio>
#include <string>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<cmath>
#include<map>
#include<iostream>
#include<functional>
#include<cstring>
#include<stack>

using namespace std;
void fastio() {
	iostream::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 2e5 + 5;
string a;
string b;
int mt[N];
long long n, k;
char chi(char x) {
	if (x == 'B')return 'W';
	return 'B';
}
int main() {
	fastio();
	cin >> n >> k;
	cin >> a;
	b = a;
	for (int i = 0; i < n; i++) {
		if (a[(i + 1) % n] == a[i] || a[(i - 1+n) % n] == a[i])
			mt[i] = 1;
	}
	int allmt = 1;
	for (int i = 0; i < n; i++) {
		if (!mt[i]) {
			allmt = 0;
			break;
		}
	}
	if (allmt) {
		cout << a;
		return 0;
	}

	int allnotmt = 1;
	for (int i = 0; i < n; i++) {
		if (mt[i]) {
			allnotmt = 0;
			break;
		}
	}
	if (allnotmt) {
		for (int i = 0; i < n; i++) {
			if (k % 2 == 0)cout << a[i];
			else cout << chi(a[i]);
		}
		return 0;
	}

	int start;
	for (start = 0; start < n; start++) {
		if (!mt[start] && mt[(start - 1 + n) % n])
			break;
	}

	for (int x = 0;x<n;) {
		while (x < n&&mt[(start + x) % n])x++;
		int cho = x;
		while (x + 1 < n && !mt[(start + x + 1) % n])x++;
		int num = (x - cho + 1);
		for (int i = cho; i <= x; i++) {
			if (i - cho < num / 2) {
				if (i - cho + 1 <= k) {
					b[(start + i) % n] = a[(start + cho - 1 + n) % n];
				}
				else {
					if (k % 2 == 1) {
						b[(start + i) % n] = chi(a[(start + i) % n]);
					}
				}
			}
			else {
				if ((x - i + 1) <= k) {
					b[(start + i) % n] = a[(start + x + 1) % n];
				}
				else {
					if (k % 2 == 1) {
						b[(start + i) % n] = chi(a[(start + i) % n]);
					}
				}
			}
		}
		x++;
	}
	cout << b;
}