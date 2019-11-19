//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[2000];
int rankk[2000];
int el[2000];
long long place[2000];
void make_set(int v) {
	el[v] = v;
	parent[v] = v;
	rankk[v] = 0;
}

int find_set(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (rankk[a] < rankk[b])
			swap(a, b);
		parent[b] = a;
		if (rankk[a] == rankk[b])
			++rankk[a];
		if (place[el[a]] < place[el[b]]) {
			place[el[b]] = 0;
		}
		else {
			place[el[a]] = 0;
			el[a] = el[b];
		}
	}
}
bool sss(pair<long long, pair<int, int>>&a, pair<long long, pair<int, int>>&b) {
	return a.first < b.first;
}
int main() {
	int n;
	cin >> n;
	vector<pair<long long, long long> >a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	vector<long long> con(n);
	for (int i = 0; i < n; i++)
		cin >> place[i];
	for (int i = 0; i < n; i++)
		cin >> con[i];
	for (int i = 0; i < n; i++) {
		make_set(i);
	}
	vector < pair<long long, pair<int, int> > >q;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			q.push_back({ ((con[i] + con[j]) * (abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second))),{i,j} });
		}
	}
	sort(q.begin(), q.end(), sss);
	vector<pair<int, int>>ansr;
	long long ans = 0;
	for (int i = 0; i < q.size(); i++) {
		int p1 = find_set(q[i].second.first);
		int p2 = find_set(q[i].second.second);
		if (p1 != p2) {
			int d1 = el[p1];
			int d2 = el[p2];
			long long cost = q[i].first;
			if (cost <= max(place[d1], place[d2])) {
				union_sets(p1,p2);
				ansr.push_back({ q[i].second.first,q[i].second.second });
				ans += q[i].first;
			}
		}
	}
	vector<int>o;
	for (int i = 0; i < n; i++) {
		ans += place[i];
		if (place[i])
			o.push_back(i+1);
	}
	cout << ans << endl<<o.size()<<endl;
	for (int i = 0; i < o.size(); i++)
		cout << o[i] << " ";
	cout << endl << ansr.size()<<endl;
	for (int i = 0; i < ansr.size(); i++)
		cout << ansr[i].first+1 << " " << ansr[i].second+1 << endl;
	return 0;
}