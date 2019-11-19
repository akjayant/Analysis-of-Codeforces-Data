#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <algorithm>
#define X first
#define Y second
#define pi 3.14159265358979323846
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
 
const int o = 1 << 17;
 
const int mod = 1000000007;
 
const int inf = 0x3f3f3f3f;
const ll huge = 100000000000000000LL;
 
typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;
typedef pair<pli, int> st;
typedef priority_queue<st> pq;

const int maxn = 15;

int n;
int a[maxn][maxn];

ld expp[maxn][maxn];

pii go(int x, int y, int d) {
	for (int i = 0; i < d; i++) {
		if (x % 2 == 0) {
			y--;
			if (y == -1) {
				x--;
				y++;			
			}		
		}
		else {
			y++;
			if (y == n) {
				x--;
				y--;			
			}
		}
		if (x == -1)
			return pii(-1, -1);
	}
	return pii(x, y);
}
 
int main() {
    ios::sync_with_stdio(false);
	n = 10;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];	
	for (int i = 0; i < n; i++) {
		int start = 0;
		int end = n;
		int step = 1;
		if (i % 2 == 1) {
			start = n - 1;
			end = -1;
			step *= -1;
		}
		for (int j = start; j != end; j += step) {
			if (i == 0 && j == 0)
				continue;
			for (int k = 1; k <= 6; k++) {
				pii w = go(i, j, k);
				if (w.X == -1)
					continue;		
				if (w.X == 0 && w.Y == 0) 
					expp[i][j] = 6;
				else
					expp[i][j] += (1 + min(expp[w.X][w.Y], expp[w.X - a[w.X][w.Y]][w.Y])) / 6;			
			}
		}
	}
	cout << setprecision(15) << expp[9][0] << endl;
    return 0;
}
