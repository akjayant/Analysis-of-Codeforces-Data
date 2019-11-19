#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
int N,a;
ll K;
map<ll,ll> m;
vector<pii> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	while (N--) {
		cin >> a;
		m[a]++;
	}
	for (auto i = m.begin(); i != m.end(); i++) {
		v.push_back(*i);
	}
	int s = 0;
	int e = v.size() - 1;
	while (s < e) {
		if (v[s].second < v[e].second) {
			if (v[s].second * (v[s + 1].first - v[s].first) <= K) {
				K -= v[s].second * (v[s + 1].first - v[s].first);
				v[s + 1].second += v[s].second;
			}
			else {
				cout << v[e].first - v[s].first - K / v[s].second;
				return 0;
			}
			s++;
		}
		else {
			if (v[e].second * (v[e].first - v[e-1].first) <= K) {
				K -= v[e].second * (v[e].first - v[e-1].first);
				v[e - 1].second += v[e].second;
			}
			else {
				cout << v[e].first - v[s].first - K / v[e].second;
				return 0;
			}
			e--;
		}
	}
	cout << 0;
}