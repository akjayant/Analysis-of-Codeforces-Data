#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, k, szv, fk;
string s, t;
bool vis[N];
vector<int> v;

int pre(int x)
{
	if (x == 0) return n-1;
	return x - 1;
}

int nxt(int x)
{
	if (x == n-1) return 0;
	return x + 1;
}

void solve(int l)
{
	int r = l;
	while (r < szv-1 && v[r+1] == v[r]+1) r++;
	for (int i = l; i <= r; ++ i)
		vis[i] = 1;
	int tmp = k;
	while (tmp-- && l <= r){
		s[v[l]] = s[pre(v[l])];
		s[v[r]] = s[nxt(v[r])];
		l++;
		r--;
	}
	if (l <= r){
		for (int i = l; i <= r; ++ i)
			s[v[i]] = s[pre(v[i])] == 'B' ? 'W' : 'B';
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k >> s;
	if (k == 0){cout << s << endl; return 0;}
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; ++ i)
		if (s[pre(i)] != s[i] && s[nxt(i)] != s[i])
			v.push_back(i), vis[i] = 1;
	if (v.size() == n){
		if (k & 1)
			for (int i = 0; i < n; ++ i)
				s[i] = s[i] == 'B' ? 'W' : 'B';
		cout << s << endl;
		return 0;
	}
	t = s;
	for (int i = 0, cnt = 0; i < n; ++ i)
		if (!vis[i] && !vis[nxt(i)]){
			if (1){
				fk = nxt(i);
				for(int j = 0; j < n; ++ j){
					t[j] = s[(j+nxt(i))%n];
				}
				s = t;
				break;
			}
		}
	v.clear();
	for (int i = 0; i < n; ++ i)
		if (s[pre(i)] != s[i] && s[nxt(i)] != s[i])
			v.push_back(i);
	memset(vis, 0, sizeof(vis));
	szv = v.size();
	for (int i = 0, sz = v.size(); i < sz; ++ i)
		if (!vis[i]){
			solve(i);
		}
	for (int i = 0; i < n; ++ i)
		t[(i+fk)%n] = s[i];
	cout << t << endl;
	return 0;
}