#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define LL long long
#define pii pair<int, int>
using namespace std;

const int maxn = 1e7 + 5;
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const long long inf = 0x3f3f3f3f;

int G[500][500];

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 1; i <= n; ++i) {
		if(i & 1) {
			for(int j = 1; j <= n; ++j) 
				G[j][i] = ++cnt;
		}
		else {
			for(int j = n; j > 0; --j)
				G[j][i] = ++cnt;
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(j - 1) cout << " ";
			cout << G[i][j];
		}
		cout << endl;
	}
	return 0;
}