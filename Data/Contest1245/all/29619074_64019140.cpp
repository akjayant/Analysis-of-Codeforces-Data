#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef unsigned long long ull;

pair<int, int> pos[2001];
ull c[2001], k[2001];
bool power[2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pos[i] = make_pair(x, y);
	}

	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> k[i];
	}

	priority_queue<pair<ull, pair<int, int> > > pq;
	for (int i = 0; i < n; i++) {
		pq.push(make_pair(-c[i], make_pair(i, i)));
	}

	ull tc = 0;
	vector<int> ra;
	vector<pair<int, int> > rb;

	int pc = 0;
	while (pc < n) {
		auto f = pq.top();
		pq.pop();

		ull cost = -f.first;
		int a = f.second.first, b = f.second.second;
		if (a == b) {
			if (power[a]) continue;

			power[a] = true;
			pc++;
			tc += cost;

			ra.push_back(a);

			for (int i = 0; i < n; i++) {
				if (power[i]) continue;
				pq.push(make_pair(-(abs(pos[a].first - pos[i].first) + abs(pos[a].second - pos[i].second)) * (k[a] + k[i]), make_pair(a, i)));
			}
		}
		else {
			if (power[b]) continue;

			power[b] = true;
			pc++;
			tc += cost;

			rb.push_back(make_pair(a, b));

			for (int i = 0; i < n; i++) {
				if (power[i]) continue;
				pq.push(make_pair(-(abs(pos[b].first - pos[i].first) + abs(pos[b].second - pos[i].second)) * (k[b] + k[i]), make_pair(b, i)));
			}
		}
	}

	cout << tc << "\n";
	cout << ra.size() << "\n";
	for (int i : ra) {
		cout << i + 1 << " ";
	}
	cout << "\n";
	cout << rb.size() << "\n";
	for (auto i : rb) {
		cout << i.first + 1 << " " << i.second + 1 << "\n";
	}
}