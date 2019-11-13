#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <cmath>
#include <functional>
#include <algorithm>
#include <utility>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <complex>
//#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long double C;
typedef complex<C> P;

#define X real()
#define Y imag()
#define Size(X) (int)X.size()
#define int long long
#define ui unsigned int
#define mp make_pair
#define timer fghge
#define y1 yjyjyju
#define all(X) (X).begin(), (X).end()
#define endl '\n'

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s, t; cin >> s >> t;
		vector<pair<int, int>> order;
		for (int i = 0; i < n; i++) 
			if (s[i] != t[i])
				order.push_back({ s[i], t[i] });
		if (order.size() != 2 && order.size() != 0) 
			cout << "NO";
		else {
			if (order[0] == order[1])
				cout << "YES";
			else
				cout << "NO";
		}
		cout << endl;
	}
	return 0;
}