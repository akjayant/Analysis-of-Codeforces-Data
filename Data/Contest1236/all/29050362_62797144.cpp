
// ~/Wiley/Atypon/RedLink/Developers/Corvus
// ~/sudo apt-get verdict Accpeted

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <functional>
#include <assert.h>
#include <complex>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 200005, M = 1005;
const ll MOD = 1e9 + 7;
const double eps = 1e-9;
const double PI = acos(-1.0);

int n, m, a[N];
vector<int> v[305];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	cin >> n;
	m = n * n;
	for (int i = 0,j=1,c=0; i < m; i++) {
		a[i] = j;
		v[j].push_back(i + 1);
		if (!c) {
			j++;
			if (j > n) {
				j--;
				c ^= 1;
			}
		}
		else {
			j--;
			if (j == 0) {
				j++;
				c ^= 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
	return 0;
}