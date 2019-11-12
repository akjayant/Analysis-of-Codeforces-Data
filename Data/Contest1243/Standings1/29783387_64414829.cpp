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

bool solve(string s, string t, int n, vector<pair<int,int> > &ans) {
	vector<vector<pair<int,int> > > pos(26,vector<pair<int,int> >());
	for (int i = 0;i<n;++i) {
		pos[s[i]-'a'].push_back({i,0});
		pos[t[i]-'a'].push_back({i,1});
	}
	bool f = 1;
	for (int i = 0;i<26;++i) 
		if (pos[i].size()%2) f = 0;
	if (!f) return 0;
	for (int i = 0;i<26;++i) {
		// cout << s<< endl <<t<<endl<<endl;
		sort(pos[i].begin(), pos[i].end());
		for (int j = 0;j<pos[i].size();j+=2) {
			if (pos[i][j].fs == pos[i][j+1].fs) continue;
			if (pos[i][j].sc != pos[i][j+1].sc) {
				if (s[pos[i][j+1].fs] != t[pos[i][j+1].fs]) {
					int p = pos[i][j+1].fs;
					ans.push_back({p,p});
					for (auto &h : pos[s[p]-'a']) {
						if (h.fs == p && h.sc == 0) {
							h.sc = 1;
							break;
						}
					}
					sort(pos[s[p]-'a'].begin(), pos[s[p]-'a'].end());
					for (auto &h : pos[t[p]-'a']) {
						if (h.fs == p && h.sc == 1) {
							h.sc = 0;
							break;
						}
					}
					sort(pos[t[p]-'a'].begin(), pos[t[p]-'a'].end());
					swap(s[p], t[p]);
				}
			}
			int lv = pos[i][j].sc;
			if (lv == 0) {
				ans.push_back({pos[i][j+1].fs, pos[i][j].fs});
				int p2 = pos[i][j+1].fs;
				int p1 = pos[i][j].fs;
				for (auto &h : pos[t[p1]-'a']) {
					if (h.fs == p1 && h.sc == 1) {
						h.fs = p2;
						h.sc = 0;
						break;
					}
				}
				sort(pos[t[p1]-'a'].begin(), pos[t[p1]-'a'].end());
				for (auto &h : pos[s[p2]-'a']) {
					if (h.fs == p2 && h.sc == 0) {
						h.fs = p1;
						h.sc = 1;
						break;
					}
				}
				sort(pos[s[p2]-'a'].begin(), pos[s[p2]-'a'].end());
				swap(s[p2], t[p1]);
			}
			else {
				ans.push_back({pos[i][j].fs, pos[i][j+1].fs});
				int p1 = pos[i][j].fs;
				int p2 = pos[i][j+1].fs;
				for (auto &h : pos[s[p1]-'a']) {
					if (h.fs == p1 && h.sc == 0) {
						h.fs = p2;
						h.sc = 1;
						break;
					}
				}
				sort(pos[s[p1]-'a'].begin(), pos[s[p1]-'a'].end());
				for (auto &h : pos[t[p2]-'a']) {
					if (h.fs == p2 && h.sc == 1) {
						h.fs = p1;
						h.sc = 0;
						break;
					}
				}
				sort(pos[t[p2]-'a'].begin(), pos[t[p2]-'a'].end());
				swap(s[p1], t[p2]);
			}
 		}
	}
	return 1;
}

void st() {
	for (int n = 1;n<=10;++n) {
		for (int i = 0;i<100;++i) {
			string s,t, _s, _t;
			for (int j = 0;j<n;++j) {
				s += 'a' + rng()%3;
				t += 'a' + rng()%3;
			}
			_s = s;
			_t = t;
			vector<pair<int,int> > ans;
			if (solve(s,t,n,ans)) {
				if (ans.size() > 2*n) cout<<"j1!!!"<<endl;
				for (auto j : ans) {
					swap(s[j.fs], t[j.sc]);
				}
				if (s != t) {
					cout << "j2!!!"<<endl;
					cout << n << " " <<_s << " " << _t <<endl;
					cout << ans.size() << endl;
					for (auto  j : ans) cout<<j.fs+1<<" "<<j.sc+1<<endl;
					return ;
				}
			}
		}
	}
}

int main() {	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int k;
	cin>>k;
	while (k--) {
		int n;
		string s,t;
		cin>>n>>s>>t;
		vector<pair<int,int> > ans;
		if (!solve(s,t,n,ans)) cout<<"No\n";
		else {
			cout<<"Yes\n";
			cout<<ans.size()<<"\n";
			for (auto i : ans) cout<<i.fs+1<<" "<<i.sc+1<<"\n";
		}
	}
	
	return 0;
}