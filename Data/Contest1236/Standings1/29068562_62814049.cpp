#include <algorithm>
#include  <iostream>
#include   <cstdlib>
#include   <cstring>
#include    <cstdio>
#include    <string>
#include    <vector>
#include    <bitset>
#include     <stack>
#include     <cmath>
#include     <deque>
#include     <queue>
#include      <list>
#include       <set>
#include       <map>
#define line printf("---------------------------\n")
#define mem(a, b) memset(a, b, sizeof(a))
#define pi acos(-1)
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const int mod = 1e9+7;
const int maxn = 1e5+10;

vector<ll> x[maxn], y[maxn];
ll n, m, k;

ll getAns(int t) {
	ll nowx = 1, nowy = 1, le = t;
	ll can, choose = 0;
	ll ans = 1;
	ll minnx = 0, maxxx = n + 1, minny = 0, maxxy = m + 1;
	while(1) {
		if(le == 0) {
			can = lower_bound(x[nowx].begin(), x[nowx].end(), nowy + 1) - x[nowx].begin();
			x[nowx][can] = min(x[nowx][can], maxxy);
			if(x[nowx][can] == nowy + 1) {
				break;
			}
			ans += x[nowx][can] - nowy - 1;
			nowy = x[nowx][can] - 1;
//			x[nowx][can] = nowy;
			minnx = nowx;
			le += 1;
			le %= 4;
		} else if(le == 1) {
			can = lower_bound(y[nowy].begin(), y[nowy].end(), nowx + 1) - y[nowy].begin();
			y[nowy][can] = min(y[nowy][can], maxxx);
			if(y[nowy][can] == nowx + 1) {
				break;
			}
			ans += y[nowy][can] - nowx - 1;
			nowx = y[nowy][can] - 1;
//			y[nowy][can] = nowx;
			maxxy = nowy;
			le += 1;
			le %= 4;
		} else if(le == 2) {
			can = lower_bound(x[nowx].begin(), x[nowx].end(), nowy) - x[nowx].begin();
			can--;
			x[nowx][can] = max(minny, x[nowx][can]);
			if(x[nowx][can] == nowy - 1) {
				break;
			}
			ans += nowy - x[nowx][can] - 1;
			nowy = x[nowx][can] + 1;
//			x[nowx][can] = nowy;
			maxxx = nowx;
			le += 1;
			le %= 4;
		} else {
			can = lower_bound(y[nowy].begin(), y[nowy].end(), nowx) - y[nowy].begin();
			can--;
			y[nowy][can] = max(y[nowy][can], minnx);
			if(y[nowy][can] == nowx - 1) {
				break;
			}
			ans += nowx - y[nowy][can] - 1;
			nowx = y[nowy][can] + 1;
//			y[nowy][can] = nowx;
			minny = nowy;
			le += 1;
			le %= 4;
		}
	}
	return ans;
}

int main() {
	cin >> n >> m >> k;
	ll a, b;
	for(int i = 1; i <= max(n, m); i++) {
		if(i <= n) {
			x[i].push_back(0);
			x[i].push_back(m + 1);
		} 
		if(i <= m) {
			y[i].push_back(0);
			y[i].push_back(n + 1);
		} 
	}
	for(int i = 0; i < k; i++) {
		cin >> a >> b;
		x[a].push_back(b);
		y[b].push_back(a);
	}
	for(int i = 1; i <= max(n, m); i++) {
		if(i <= n) {
			sort(x[i].begin(), x[i].end());
		} 
		if(i <= m) {
			sort(y[i].begin(), y[i].end());
		} 
	}
	ll ans = lower_bound(y[1].begin(), y[1].end(), 1) - y[1].begin();
	ans = y[1][ans] - 1;
//	x[1][0] = 1;
//	y[1][0] = 1;
	ans = max(getAns(0), ans);
	if(ans + k == n * m) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}