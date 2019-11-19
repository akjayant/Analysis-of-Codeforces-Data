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

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	sort(a.begin(), a.end());
	int dx = 0, dy = 0;
	for (int i = 0; i < n / 2; ++i)
		dy += a[i];
	for (int i = n / 2; i < n; ++i)
		dx += a[i];
	
	cout << dx * 1ll * dx + dy * 1ll * dy << endl;
	return 0;
}