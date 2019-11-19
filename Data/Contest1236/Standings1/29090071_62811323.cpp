#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cassert>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<deque>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<string.h>
#include<string>
#include<iomanip>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FOR(i,k,n) for(int i = k ; i < n ; ++i)
#define REP(i,k,n) for(int i = k ; i <= n ; ++i)
#define sz(x) (int)x.size()
#define VAR(x) #x << " " << x
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;

static const int N=1e5 + 10;
ll n, m, k;

pair<int,int> ob[N];
deque<int> col[N], row[N];
vector<int> colVec[N], rowVec[N];

int main() {
	boost;
	cin >> n >> m >> k;
	ll ans = n*m - k-1;
	for (int i = 0; i < k; ++i) {
		cin >> ob[i].st >> ob[i].nd;
		colVec[ob[i].nd].pb(ob[i].st);
		rowVec[ob[i].st].pb(ob[i].nd);
	}
	for (int i = 1 ; i<= n; ++i) {
		sort(all(rowVec[i]));

		for (auto c : rowVec[i]) {
			row[i].push_back(c);
		}
	}
	for (int i = 1 ; i<= m; ++i) {
		sort(all(colVec[i]));
		for (auto c: colVec[i])
			col[i].push_back(c);
	}
	bool moved = false;
	int top = 0, bottom = n+1, right = m+1, left = 0;
	int x = 1;
	int y = 1;
	int dir = 1;
	while(true) {
		// cout << x << " " << y << " " << ans << "\n";;
		if(dir == 1) {
			int closestObstacle = right;
			while (sz(row[x]) && row[x].front() < y) {
				row[x].pop_front();
			}
			if (sz(row[x])) {
				closestObstacle = min(closestObstacle, row[x].front());
			}
			// cout << closestObstacle << " " << x << " " << y << " xd\n";
			if (abs(closestObstacle-y) == 1 && moved) break;
			moved = true;
			ans -= (closestObstacle - y - 1);
			y = closestObstacle-1;
			top = x;
		}
		else if (dir == 3) {
			int closestObstacle = left;
			while (sz(row[x]) && row[x].back() > y) {
				row[x].pop_back();
			}
			if (sz(row[x])) {
				closestObstacle = max(closestObstacle, row[x].back());
			}
			// cout << closestObstacle << " " << x << " " << y << " XD\n";
			if (abs(closestObstacle-y) == 1) break;
			ans -= (y - closestObstacle - 1);
			y = closestObstacle+1;
			bottom = x;
		}
		else if (dir == 2) {
			int closestObstacle = bottom;
			while (sz(col[y]) && col[y].front() < x) {
				col[y].pop_front();
			}
			if (sz(col[y])) {
				closestObstacle = min(closestObstacle, col[y].front());
			}

			if (abs(closestObstacle-x) == 1) break;
			ans -= (closestObstacle - x - 1);
			x = closestObstacle-1;
			right = y;
		}
		else if (dir == 4) {
			int closestObstacle = top;
			while (sz(col[y]) && col[y].back() > x) {
				col[y].pop_back();
			}
			if (sz(col[y])) {
				closestObstacle = max(closestObstacle, col[y].back());
			}
			// cout << ">" << closestObstacle << " " << x << " " << y << "\n";
			if (abs(closestObstacle-x) == 1) break;
			ans -= (x - closestObstacle - 1);
			x = closestObstacle+1;
			left = y;	
		}
		dir++;
		if (dir == 5) dir = 1;
	}
	if (ans == 0) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
}