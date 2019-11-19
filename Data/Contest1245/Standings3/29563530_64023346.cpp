#include <bits/stdc++.h>

using namespace std;

struct City {
	int x, y;
	int c, k;
	bool conn = false;
};

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	vector<City> cities(n);
	for(int i = 0; i < n; i++) {
		cin >> cities[i].x;
		cin >> cities[i].y;
	}
	for(int i = 0; i < n; i++) {
		cin >> cities[i].c;
	}
	for(int i = 0; i < n; i++) {
		cin >> cities[i].k;
	}


	priority_queue<pair<long long, pair<int, int>>> pq;
	for(int i = 0; i < n; i++) {
		pq.push(make_pair(-cities[i].c, make_pair(i, i)));
	}

	vector<int> plants;
	vector<pair<int, int>> edges;

	long long sum = 0;
	int connected = 0;
	while(connected < n) {
		auto path = pq.top();
		pq.pop();

		long long cost = -path.first;
		int nc = path.second.first;
		int oc = path.second.second;

		if(cities[nc].conn) continue;
		sum += cost;
		connected++;
		cities[nc].conn = true;

		if(nc == oc) {
			plants.push_back(nc);
		}
		else {
			edges.push_back(make_pair(nc, oc));
		}

		for(int i = 0; i < n; i++) {
			if(cities[i].conn) continue;

			long long dx = abs(cities[i].x - cities[nc].x);
			long long dy = abs(cities[i].y - cities[nc].y);
			long long ncost = (dx+dy) * (cities[i].k + cities[nc].k);
			pq.push(make_pair(-ncost, make_pair(i, nc)));
		}
	}

	cout << sum << endl;
	string sep = "";
	cout << plants.size() << endl;
	for(int plant : plants) {
		cout << sep << plant+1;
		sep = " ";
	}
	cout << endl;

	cout << edges.size() << endl;
	if(edges.size() > 0) {
		for(auto edge : edges) {
			cout << edge.first+1 << " " << edge.second+1 << endl;
		}
	}

	return 0;
}
