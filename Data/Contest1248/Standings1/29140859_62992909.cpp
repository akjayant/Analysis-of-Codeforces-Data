#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>

using namespace std;

const long long mod = 1000000007;

int main() {
	int n, m;
	cin >> n >> m;
	if (n < m)
		swap(n, m);
	if (n == 1 && m == 1) {
		cout << 2;
		return 0;
	}
	
	if (m == 1) {
		vector<long long> d00(n);
		vector<long long> d01(n);
		vector<long long> d10(n);
		vector<long long> d11(n);
		d00[1] = 1;
		d01[1] = 1;
		d10[1] = 1;
		d11[1] = 1;
		for (int i = 2; i < n; ++i) {
			d00[i] = d10[i - 1];
			d10[i] = (d01[i - 1] + d11[i - 1]) % mod;
			d11[i] = d01[i - 1];
			d01[i] = (d10[i - 1] + d00[i - 1]) % mod;
		}
		
		long long cnt = (d00[n - 1] + d01[n - 1] + d10[n - 1] + d11[n - 1]) % mod;
		
		cout << cnt;
		return 0;
	}
	
	long long cnt1 = 0;
	{
		vector<long long> d00(n);
		vector<long long> d01(n);
		vector<long long> d10(n);
		vector<long long> d11(n);
		d00[1] = 1;
		d01[1] = 1;
		d10[1] = 1;
		d11[1] = 1;
		for (int i = 2; i < n; ++i) {
			d00[i] = d10[i - 1];
			d10[i] = (d01[i - 1] + d11[i - 1]) % mod;
			d11[i] = d01[i - 1];
			d01[i] = (d10[i - 1] + d00[i - 1]) % mod;
		}
		
		cnt1 = (d00[n - 1] + d01[n - 1] + d10[n - 1] + d11[n - 1]) % mod;
	}
	
	long long cnt2 = 0;
	{
		vector<long long> d00(m);
		vector<long long> d01(m);
		vector<long long> d10(m);
		vector<long long> d11(m);
		d00[1] = 1;
		d01[1] = 1;
		d10[1] = 1;
		d11[1] = 1;
		for (int i = 2; i < m; ++i) {
			d00[i] = d10[i - 1];
			d10[i] = (d01[i - 1] + d11[i - 1]) % mod;
			d11[i] = d01[i - 1];
			d01[i] = (d10[i - 1] + d00[i - 1]) % mod;
		}
		
		cnt2 = (d00[m - 1] + d01[m - 1] + d10[m - 1] + d11[m - 1]) % mod;
	}
	
	cout << (cnt1 + cnt2 - 2 + mod) % mod;
	
	return 0;
}