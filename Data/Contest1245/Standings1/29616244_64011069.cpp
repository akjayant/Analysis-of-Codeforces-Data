#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN=2e3+5;
int n;
ll x[MAXN], y[MAXN], k[MAXN], w[MAXN][MAXN];
pair<ll, int> md[MAXN];
bool vis[MAXN];
ll a1;
vector<pair<int, int>> a2, a4;
vector<int> a3;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> x[i] >> y[i];
	}

	for(int i=1; i<=n; ++i) {
		cin >> w[0][i];
		w[i][0]=w[0][i];
	}

	for(int i=1; i<=n; ++i) {
		cin >> k[i];
	}

	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			w[i][j]=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
		}
	}

	for(int i=1; i<=n; ++i) {
		md[i]=make_pair(LLONG_MAX, -1);
	}

	for(int i=0; i<=n; ++i) {
		int mi=-1;
		for(int j=0; j<=n; ++j) {
			if(!vis[j]&&(mi<0||md[j]<md[mi])) {
				mi=j;
			}
		}
		vis[mi]=1;
		a1+=md[mi].first;
		a2.push_back(make_pair(md[mi].second, mi));
		for(int j=0; j<=n; ++j) {
			md[j]=min(md[j], make_pair(w[mi][j], mi));
		}
	}

	a2.erase(a2.begin());

	for(int i=0; i<a2.size(); ++i) {
		if(!a2[i].first) {
			a3.push_back(a2[i].second);
		} else {
			a4.push_back(a2[i]);
		}
	}

	cout << a1 << "\n";
	cout << a3.size() << "\n";
	for(int i=0; i<a3.size(); ++i) {
		cout << a3[i] << " ";
	}
	cout << "\n";
	cout << a4.size() << "\n";
	for(int i=0; i<a4.size(); ++i) {
		cout << a4[i].first << " " << a4[i].second << "\n";
	}

	return 0;
}