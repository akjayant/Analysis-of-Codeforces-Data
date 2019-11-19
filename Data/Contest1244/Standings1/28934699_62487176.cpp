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
const int N = 1e5 + 5;
long long a[N];

int main() {
	fastio();
	long long n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++)cin >> a[i];
	sort(a+1, a + n+1);

	long long dap = a[n] - a[1];

	int l = 1, r = n;

	long long point = k;
	while (l < r) {
		long long nl = l, nr = n - r + 1;
		if (nl < nr) {
			long long h = a[l + 1] - a[l];
			if (h*nl > point) {
				dap -= point / nl;
				break;
			}
			else {
				point -= h * nl;
				dap -= h;
				l++;
			}
		}
		else {
			long long h = a[r] - a[r-1];
			if (h*nr > point) {
				dap -= point / nr;
				break;
			}
			else {
				point -= h * nr;
				dap -= h;
				r--;
			}
		}
	}
	cout << dap;
}