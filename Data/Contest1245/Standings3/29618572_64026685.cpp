#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <string>
#include <queue>

using namespace std;

struct TT {
	int64_t c;
	int64_t f;
	int64_t t;
};

class comp {
public:
	bool operator()(TT& a, TT& b) {
		if (a.c != b.c) {
			return a.c > b.c;
		} else if (a.f != b.f) {
			return a.f < b.f;
		} else {
			return a.t < b.t;
		}
	}
};

int main() {
	int64_t n;
	cin >> n;
	vector<int64_t> x(n);
	vector<int64_t> y(n);
	vector<int64_t> c(n);
	vector<int64_t> k(n);
	vector<int64_t> good(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> k[i];
	}

	priority_queue<TT, vector<TT>, comp> q;

	vector<int64_t> el;
	vector<pair<int64_t, int64_t>> pr;
	for (int i = 0; i < n; ++i) {
		q.push(TT{c[i], i, i});
	}
	int ccg = 0;
	int64_t cost = 0;
	while (ccg < n) {
		auto t = q.top();
		q.pop();
		if (good[t.t] && good[t.f]) {
			continue;
		}
		if (t.f == t.t) {
			el.push_back(t.f);
		} else {
			pr.push_back({t.f, t.t});
		}
		cost += t.c;
		good[t.t] = 1;
		ccg++;
		for (int i = 0; i < n; ++i) {
			if (!good[i]) {
				int64_t c = (k[i] + k[t.t])* (abs(x[i] - x[t.t]) + abs(y[i] - y[t.t]));
				q.push(TT{c, t.t, i});
			}
		}
	}
	cout << cost << '\n';
	cout << el.size() << '\n';
	for (auto& i : el) {
		cout << i + 1 << ' ';
	} cout << '\n';
	cout << pr.size() << '\n';
	for (auto& i : pr) {
		cout << i.first + 1 << ' ' << i.second + 1 << '\n';
	} cout << '\n';
}