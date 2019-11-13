#include <bits/stdc++.h>
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

void solve() {
	int n;
	string s, t;
	V<pi> v;
	int cnt[26] = {};
	cin >> n >> s >> t;
	for(char c:s) cnt[c-'a']++;
	for(char c:t) cnt[c-'a']++;
	for(int i=0;i<26;i++)
		if(cnt[i] & 1) {
			cout << "No" << endl;
			return;
		}
	cout << "Yes" << endl;
	for(int i=0;i<n;i++) {
		if(s[i] == t[i]) continue;
		int j;
		for(j=i+1;j<n;j++) if(s[j] == s[i]) break;
		if(j < n) {
			swap(s[j], t[i]);
			v.EB(j, i);
			continue;
		}
		for(j=i+1;j<n;j++) if(t[j] == s[i]) break;
		assert(j < n && t[j] == s[i]);
		swap(s[j], t[j]);
		v.EB(j, j);
		swap(s[j], t[i]);
		v.EB(j, i);
	}
	cout << v.size() << endl;
	for(pi p:v) cout << p.first+1 << " " << p.second+1 << endl;
}

int main()
{
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int k;
	cin >> k;
	while(k--) {
		solve();
	}
	
}
