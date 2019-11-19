#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,mmx,abm,popcnt")
using namespace std;
#define fs first
#define sc second
typedef long long ll;
typedef long double ld;
mt19937 rng(time(NULL));
const int maxn = 1e5 + 100;
const int mod = 1e9 + 7;
const int inf = 1e9;
const ld eps = 1e-9;

int p[maxn];

int get(int v) {
	if (p[v] == v) return v;
	return p[v] = get(p[v]);
}

void un(int a, int b) {
	a = get(a);
	b = get(b);
	if (rng()%2) swap(a,b);
	p[a] = b;
}

int main() {	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// int k;
	// cin>>k;
	// while (k--) {
	// 	int n;
	// 	string s,t;
	// 	cin>>n>>s>>t;
	// 	vector<int> cnt(26,0), cnt2(26,0);
	// 	for (int i = 0;i<n;++i) {
	// 		cnt[s[i]-'a']++;
	// 		cnt2[t[i]-'a']++;
	// 	}
	// 	// bool f = 1;
	// 	// for (int i = 0;i<26;++i) if (cnt[i] != cnt2[i]) f = 0;
	// 	// 	if (!f) {
	// 	// 		cout<<"No\n";
	// 	// 		continue;
	// 	// 	}
	// 	vector<int> p;
	// 	for (int i = 0;i<n;++i) {
	// 		if (s[i] != t[i]) p.push_back(i);
	// 	}
	// 	if (p.size() == 0)
	// 		cout << "Yes\n";
	// 	else if (p.size() == 2) {
	// 		if (s[p[0]] == s[p[1]] && t[p[0]] == t[p[1]]) cout<<"Yes\n";
	// 		else if (s[p[0]] == t[p[1]] && s[p[1]] == t[p[0]]) cout<<"Yes\n";
	// 		else cout<<"No\n"; 
	// 	}
	// 	else cout<<"No\n";

	// }
	int n,m;
	cin>>n>>m;
	set<pair<int,int> > s;
	vector<int> cnt(n,0);
	for (int i = 0;i<m;++i) {
		int a,b;
		cin>>a>>b;
		a--; b--;
		s.insert({a,b});
		s.insert({b,a});
		cnt[a]++;
		cnt[b]++;
	}
	for (int i = 0;i<n;++i) p[i] = i;
	if (n < 1) {
		for (int i = 0;i<n;++i) {
			for (int j = i+1;j<n;++j) {
				if (s.find({i,j}) == s.end()) un(i,j);
			}
		}
	}
	else {
		for (int i = 0;i<n;++i) {
			if (n - cnt[i] < 100) {
				for (int j = 0;j<n;++j)
					if (s.find({i,j}) == s.end()) un(i,j);
			}
			else {
				for (int h = 0;h<30;++h) {
					int j = rng()%n;
					if (s.find({i,j}) == s.end()) un(i,j);
				}
			}
		}
	}
	int ans = 0;
	for (auto i : s) {
		if (get(i.fs) != get(i.sc)) {
			ans++;
			un(i.fs, i.sc);
		}
	}
	cout<<ans;
	return 0;
}