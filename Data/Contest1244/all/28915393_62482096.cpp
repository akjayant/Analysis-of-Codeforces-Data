//                             In The Name Of Allah
#include <bits/stdc++.h>
#define ss second
#define ff first
#define use_fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ret(n) return cout << n, 0
#define se(n) cout << setprecision(n) << fixed
#define pb push_back
#define int long long
using namespace std; 
 
const int N = 1e6 + 100, OO = 1e18, M = 1e9 + 7, P = 6151, sq = 360, lg = 23;
typedef pair <int, int> pii;
int a[N], n, k;
map <int, int> mp;
set <int> s;

int32_t main() {
    use_fast;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert(a[i]);
		mp[a[i]]++;
	}
	while(s.size() != 1) {
		int b = *s.begin(), r = *s.rbegin();
		if(mp[b] < mp[r]) {
			s.erase(*s.begin());
			int u = *s.begin();
			if(k >= (u - b) * mp[b]) {
				k -= (u - b) * mp[b];
				mp[u] += mp[b];
				mp[b] = 0;
			}
			else {
				k = k / mp[b];
				s.insert(b + k);
				break;
			}
		}
		else {
			s.erase(*s.rbegin());
			int u = *s.rbegin();
			if(k >= (r - u) * mp[r]) {
				k -= (r - u) * mp[r];
				mp[u] += mp[r];
				mp[r] = 0;
			}
			else {
				k = k / mp[r];
				s.insert(r - k);
				break;
			}		
		}
	}
	cout << *s.rbegin() - *s.begin() << endl;
	return 0;
} 
/*
be carefull :
1- if not solve after 20 min, read again twice
2- after submit read the code again
3- fun with contest
4- ... 
*/
