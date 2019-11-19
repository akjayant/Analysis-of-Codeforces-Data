#include <bits/stdc++.h>

using namespace std;
string to_string(string s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

struct edge {
	int v, u;
	long long w;
};

const int N = 2010, mod = 1e9 + 7;


int main() {
	#ifdef LOCAL
	freopen("in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<edge> a;
	vector<int> x(n), y(n), c(n), k(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++) {
		long long t;
		cin >> t;
		a.push_back((edge){2000, i, t});
	}
	for (int i = 0; i < n; i++) {
		cin >> k[i];
	}
	
	function<long long(int, int)> getd = [&](int i ,int j) {
		return (long long)(abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]);
	};
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			a.push_back((edge){i, j, getd(i, j)});
		}
	}
	sort(a.begin(), a.end(), [](edge i, edge j) {
		return i.w < j.w;
	});
	vector<int> plant, fa(2010);
	
	function<int(int)> find = [&](int t) {
		return fa[t] == t ? t : fa[t] = find(fa[t]);
	};
	
	iota(fa.begin(), fa.end(), 0);
	vector<pair<int, int>> path;
	long long cost = 0;
	for (int i = 0; i < a.size(); i++) {
		auto u = a[i].u, v = a[i].v;
		auto w = a[i].w;
//		cerr << u << ' ' << v << ' ' << w << endl;
		if (find(u) == find(v)) continue;
		if (v == 2000 || u == 2000) {
			if (u == 2000) swap(u, v);
			plant.push_back(u);
		} else {
			path.push_back({u, v});
		}
		fa[find(u)] = find(v);
		cost += w;
	}
	cout << cost << endl;
	cout << plant.size() << endl;
	for (auto e : plant) cout << e + 1 << " ";
	cout << endl << path.size() << endl;
	for (auto e : path) cout << e.first + 1 << " " << e.second + 1 << endl;
    return 0;
}