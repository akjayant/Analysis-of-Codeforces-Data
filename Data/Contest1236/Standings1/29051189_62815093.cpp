//                             In The Name Of Allah
#include <bits/stdc++.h>
#define ss second
#define ff first
#define use_fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ret(n) r1eturn cout << n, 0
#define se(n) cout << setprecision(n) << fixed
#define pb push_back
#include <vector>
#define int long long
using namespace std; 
 
const int N = 2e5 + 1000, OO = 1e18, M = 1e9 + 7, P = 6151, sq = 1e3, lg = 60;
typedef pair <int, int> pii;

map <pii, bool> mp;
int x[N], y[N];
vector <int> vx[N], vy[N];

int32_t main() {
	use_fast;
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++) {
		cin >> x[i] >> y[i];
		mp[{x[i], y[i]}] = true;
		vx[x[i]].pb(y[i]);
		vy[y[i]].pb(x[i]);
	}
	for(int i = 1; i <= n; i++) {
		sort(vx[i].begin(), vx[i].end());
		sort(vy[i].begin(), vy[i].end());
	}
	int n1 = 1, n2 = n, m1 = 1, m2 = m, t = true;
	while(n1 <= n2 && m1 <= m2) {
		if(t) {
			int m3 = 0;
			for(int i = m2; i >= m1; i--) {
				if(mp[{n1, i}])
					continue;
				m3 = i;
				break;
			}
			for(int i = m3 + 1; i <= m2; i++)
				for(int j = n1; j <= n2; j++) 
					if(mp[{j, i}] != true)
						return cout << "No", 0;
			m2 = m3;
			int n3 = 0;
			for(int i = n2; i >= n1; i--) {
				if(mp[{i, m2}])
					continue;
				n3 = i;
				break;
			}
			for(int i = n3 + 1; i <= n2; i++) 
				for(int j = m1; j <= m2; j++) 
					if(mp[{i, j}] != true)
						return cout << "No", 0;
			n2 = n3;
			int z = (upper_bound(vy[m2].begin(), vy[m2].end(), n2) - vy[m2].begin()) - (lower_bound(vy[m2].begin(), vy[m2].end(), n1) - vy[m2].begin());
			if(z != 0) {
				return cout << "No", 0;
			}
			z = (upper_bound(vx[n1].begin(), vx[n1].end(), m2) - vx[n1].begin()) - (lower_bound(vx[n1].begin(), vx[n1].end(), m1) - vx[n1].begin());
			if(z != 0)
				return cout << "No", 0;
			t = 1 - t;
			n1++;
			m2--;
			if(mp[{n2, m2}]) {
				for(int i = n1; i <= n2; i++) 
					for(int j = m1; j <= m2; j++)	
						if(!mp[{i, j}])
							return cout << "No", 0;
				cout << "Yes" << endl;
				return 0;
			}

			continue;
		}
		else {
			int m3 = 0;
			for(int i = m1; i <= m2; i++) {
				if(mp[{n2, i}])
					continue;
				m3 = i;
				break;
			}
			for(int i = m1; i < m3; i++)
				for(int j = n1; j <= n2; j++) 
					if(mp[{j, i}] != true)
						return cout << "No", 0;
			m1 = m3;
			int n3 = 0;
			for(int i = n1; i <= n2; i++) {
				if(mp[{i, m3}])
					continue;
				n3 = i;
				break;
			}
			for(int i = n1; i < n3; i++) 
				for(int j = m1; j <= m2; j++) 
					if(mp[{i, j}] != true)
						return cout << "No", 0;
			n1 = n3;
			int z = (upper_bound(vy[m1].begin(), vy[m1].end(), n2) - vy[m1].begin()) - (lower_bound(vy[m1].begin(), vy[m1].end(), n1) - vy[m1].begin());
			if(z != 0) 
				return cout << "No", 0;
			z = (upper_bound(vx[n2].begin(), vx[n2].end(), m2) - vx[n2].begin()) - (lower_bound(vx[n2].begin(), vx[n2].end(), m1) - vx[n2].begin());
			if(z != 0)
				return cout << "No", 0;
			n2--, m1++;
			if(mp[{n1, m1}]) {
				for(int i = n1; i <= n2; i++) 
					for(int j = m1; j <= m2; j++)	
						if(!mp[{i, j}])
							return cout << "No", 0;
				cout << "Yes" << endl;
				return 0;				
			}
			t = 1 - t;
		}
	}
	cout << "Yes" << endl;
	return 0;
} 
/*
be carefull :
1- if not solve after 20 min, read again twice
2- after submit read the code again
3- fun with contest
4- ... 
*/
