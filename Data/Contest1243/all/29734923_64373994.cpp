#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <map>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <set>

using namespace std;
using ll = long long;


#define SZ(a) a.size()
#define pb(a) push_back(a)
#define ALL(a) a.begin(), a.end()
#define mp(a,b) make_pair(a,b)

const ll mod = 1000000000 + 7;

int main() {
	//ifstream cin("input.txt");
	int k;
	cin >> k;
	while (k--)
	{
		int n;
		cin >> n;
		vector <int> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		int M = 0;
		int ans = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			M = arr[i];
			ans = max(ans, min(M, n - i));
		}
		cout << ans << '\n';
	}

	return 0;
}