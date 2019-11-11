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
 
int main() {
    ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x, y;
		cin >> x >> y;
		int gcd = 0;
		for (int j = 1; j <= min(x, y); j++)
			if (x % j == 0 && y % j == 0)
				gcd = j;	
		if (gcd == 1)
			cout << "Finite" << endl;
		else
			cout << "Infinite" << endl;
	}
    return 0;
}
