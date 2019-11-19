#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

typedef long long ll;

using namespace std;

int v[2003];
ll k[2003],c[2003];
ll x[2003], y[2003];
set<pair<ll, pair<int,int>>> eset;
vector < pair<ll, pair<int, int>> > ans;
vector<int> powerstations;
vector<pair<int, int>> citypairs;

ll myabs(ll a) {
	if (a < 0ll)
		return -a;
	return a;
}

int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= n; i++)
		cin >> k[i];
	v[0] = 1;
	for (int i = 1; i <= n; i++)
		eset.insert({ c[i],{0,i} });
	ll mstcost = 0;
	while (!eset.empty()) {
		auto it = *eset.begin();
		eset.erase(eset.begin());
		if (v[it.second.second])
			continue;
		v[it.second.second] = 1;
		mstcost += it.first;
		ans.push_back(it);
		for (int j = 1; j <= n; j++) {
			int i = it.second.second;
			if (!v[j]) {
				ll dist = myabs(x[i] - x[j]) + myabs(y[i] - y[j]);
				dist *= (k[i] + k[j]);
				eset.insert({ dist,{i,j} });
			}
		}
	}
	cout << mstcost << "\n";
	for (auto it : ans) {
		if (it.second.first == 0)
			powerstations.push_back(it.second.second);
		else if (it.second.second == 0)
			powerstations.push_back(it.second.first);
		else
			citypairs.push_back(it.second);
	}
	cout << (int)powerstations.size() << "\n";
	for (auto it : powerstations)
		cout << it << " ";
	cout << "\n" << (int)citypairs.size() << "\n";
	for (auto it : citypairs)
		cout << it.first << " " << it.second << "\n";
	//system("pause");
	return 0;
}