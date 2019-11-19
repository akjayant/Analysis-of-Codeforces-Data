#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define ll long long int
#define fill(space,a) memset(space,a,sizeof(space))
#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);

int n;
ll x[2005], y[2005], c[2005], k[2005];
pair <ll, pair<int, int> > p[2005*2005];
ll id[2005];
ll edges = 0LL;
ll mstcost = 0LL;
void init(){
	for (int i = 0; i < 2005; ++i)
		id[i] = i;
}

int root(int x){
	while (id[x] != x){
		id[x] = id[id[x]];
		x = id[x];
	}
	return x;
}

void union1(int x, int y){
	int p = root(x);
	int q = root(y);
	id[p] = id[q];
}

vector <pii> mstedges;

void kruskal() {
	int x, y;
	ll cost = 0LL;;
	for (int i = 0; i < edges; ++i){
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;
		if (root(x) != root(y)){
			mstcost += cost;
			mstedges.pb(mp(x, y));
			union1(x, y);
		}
	}
}

int main()
{
	optimize();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
	}
	init();
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ll w = (k[i] + k[j])*(abs(x[i] - x[j]) + abs(y[i] - y[j]));
			p[edges] = mp(w, mp(i, j));
			edges++;
		}
	}

	for (int i = 1; i <= n; i++) {
		ll w = c[i];
		p[edges] = mp(w, mp(0, i));
		edges++;
	}

	sort(p, p + edges);
	
	kruskal();
	cout << mstcost << endl;
	ll e = 0LL, city = 0LL;
	vector <int> cityid;
	for (int i = 0; i < mstedges.size(); i++) {
		if (mstedges[i].first != 0)
			e++;
		else {
			city++;
			cityid.pb(mstedges[i].second);
		}
	}
	cout << city << endl;
	for (int i = 0; i < city; i++) {
		cout << cityid[i] << " ";
	}
	cout << endl;
	cout << e << endl;
	for (int i = 0; i < (int)mstedges.size(); i++) {
		if(mstedges[i].first != 0)	
			cout << mstedges[i].first << " " << mstedges[i].second << endl;
	}

	return 0;
}