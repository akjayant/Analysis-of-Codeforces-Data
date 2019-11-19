#include <iostream> 
#include <algorithm>  
#include <vector>
#include <stdio.h>
#include <string>
#include <map>
#include <numeric>
#include <stack>
#include <set>
#include <math.h>
#include <iomanip>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<int> l(n);
	for (int i = 0; i < n; i++) cin >> l[i];
	sort(l.begin(), l.end());
	auto it = l.begin();
	long long a = 0, b = 0;
	for (int i = 0; i <= n / 2 - 1; ++i, ++it) a += *it;
	for (; it != l.end(); ++it) b += *it;
	cout << a * a + b * b << endl;

	return 0;
}