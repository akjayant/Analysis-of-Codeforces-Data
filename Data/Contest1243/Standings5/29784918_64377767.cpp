#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int k;
	cin >> k;
	while (k--) {
		int n;
		cin >> n;
		vector<int> line(n, 0);
		for (int i = 0; i < n; ++i) cin >> line[i];
		sort(line.rbegin(), line.rend());
		int mx = 0;
		for (int i = 0; i < n; ++i) {
			if (line[i] >= i + 1) mx = i + 1;
		}
		cout << mx << endl;
	}
	return 0;
}