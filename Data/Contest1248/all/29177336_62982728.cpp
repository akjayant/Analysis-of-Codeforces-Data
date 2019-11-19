#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <set>

using namespace std;

typedef long long ll;
int a[100000];

int main() {
	ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
//	freopen("D:\\Projects\\CPP\\UVa\\CF574\\a.in", "r",stdin);
//	freopen("D:\\Projects\\CPP\\UVa\\CF574\\a.out", "w",stdout);
#else
//	freopen("input.txt","r",stdin);
//	freopen("output.txt", "w",stdout);
#endif
	int n;
	cin >> n;
        for (int i = 0; i < n; i++) {
		cin >> a[i];
        }
	sort(a, a + n);
	int mid = n / 2;
	ll dx = 0;
	ll dy = 0;
	for (int i = 0; i < mid; ++i)
		dx += a[i];
	for (int i = mid; i < n; ++i)
		dy += a[i];
	cout << dx * dx + dy * dy << endl;
	return 0;
}