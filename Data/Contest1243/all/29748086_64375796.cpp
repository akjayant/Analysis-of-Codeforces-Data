#include <iostream> 
#include <list> 
#include <limits.h> 
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <unordered_set>

#define ll long long

using namespace std;

int main() {
	// freopen("in.txt", "r", stdin);	
	int queries;
	cin >> queries;

	for (int t = 0; t < queries; t++) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				int height = v[i];
				int width = j - i + 1;
				ans = max(ans, min(width, height));
			}
		}

		cout << ans << endl;
	}
	return 0;
}









