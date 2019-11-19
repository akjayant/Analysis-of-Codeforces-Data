// Author : Apaar
// Built  : 01-11-2019 21:24:36

#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define PP pair<int,pair<int,int>>
#define pb push_back
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N = 2005;

vector<P> gr[N], edge;
int il[N];

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		int a[n], b[n], c[n], d[n];
		for (i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}
		for (i = 0; i < n; i++) {
			cin >> c[i];
		}
		for (i = 0; i < n; i++) {
			cin >> d[i];
		}
		vector<P> temp;
		for (i = 0; i < n; i++) {
			for (j = i + 1; j < n; j++) {
				cnt = (d[i] + d[j]) * (abs(a[i] - a[j]) + abs(b[i] - b[j]));
				gr[i].pb({j, (d[i] + d[j]) * (abs(a[i] - a[j]) + abs(b[i] - b[j]))});
				gr[j].pb({i, (d[i] + d[j]) * (abs(a[i] - a[j]) + abs(b[i] - b[j]))});
				// db(i, cnt);
			}
			temp.pb({c[i], i});
		}
		sort(temp.begin(), temp.end());
		vector<int> ps;
		priority_queue<PP, vector<PP>, greater<PP>> Q;
		for (i = 0; i < n; i++) {
			Q.push({c[i], {i, i}});
		}
		while (!Q.empty()) {
			PP p = Q.top();
			Q.pop();
			int cur = p.S.F;
			int nxt = p.S.S;
			int dis = p.F;
			if (il[cur]) continue;
			if (cur != nxt) {
				edge.pb({cur, nxt});
				ans += dis;
			}
			else {
				ps.pb(cur);
				ans += dis;
			}
			il[cur] = 1;
			for (i = 0; i < (int)(gr[cur].size()); i++) {
				int to = gr[cur][i].F, w = gr[cur][i].S;
				if (!il[to]) {
					Q.push({w, {to, cur}});
				}
			}
		}
		cout << ans << '\n';
		cout << (int)(ps.size()) << '\n';
		for (auto x : ps) cout << x + 1 << " ";
		cout << '\n';
		cout << (int)(edge.size()) << '\n';
		for (auto x : edge) cout << x.F + 1 << " " << x.S + 1 << '\n';
	}
}