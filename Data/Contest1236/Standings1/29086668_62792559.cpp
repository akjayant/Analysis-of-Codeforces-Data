#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <climits>
#include <bitset>
#include <functional>
#include <iomanip>

#define FOR_LT(i, beg, end) for (int i = beg; i < end; i++)
#define FOR_LE(i, beg, end) for (int i = beg; i <= end; i++)
#define FOR_DW(i, beg, end) for (int i = beg; end <= i; i--)

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	vector<vector<int>> ans(n, vector<int>(n));

	FOR_LT(i, 0, n * n) {
		int c = 0;
		if ((i / n) & 1) {
			c = n - 1 - (i % n);
		}
		else {
			c = i % n;
		}
		int r = i / n;
 		ans[c][r] = n * n - i;
	}

	FOR_LT(i, 0, n) {
		FOR_LT(j , 0, n) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	

	return 0;
}