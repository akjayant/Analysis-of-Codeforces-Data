#include<bits/stdc++.h>
using namespace std;
string to_string(const string& s) {
	return '"' + s + '"';
}
string to_string(const bool b) {
	return (b ? "true" : "false");
}
string to_string(const char* s) {
	return to_string((string)s);
}
string to_string(const char c) {
	string s = "'";
	s += c;
	s += "'";
	return s;
}
template<class T, class U>
string to_string(const pair<T, U>& p) {
	string s = "(";
	s += to_string(p.first);
	s += ", ";
	s += to_string(p.second);
	s += ")";
	return s;
}
template<class T>
string to_string(const T& a) {
	bool first = true;
	string s = "{";
	for (const auto& x : a) {
		if(!first){
			s += ", ";
		}
		first = false;
		s += to_string(x);
	}
	s += "}";
	return s;
}
void debug_out() {cerr << '\n';}
template<class Head, class... Tail>
void debug_out(Head head, Tail... tail) {
	cerr << ' ' << to_string(head);
	debug_out(tail...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif
using ll = long long;
using ld = long double;
const int mod = 1e9 + 7;
const int inf = 1e9 + 100;
const ll inf64 = 7e18l;
void solve() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	vector<pair<int, int>> answer;
	for (int i = 0; i < n; ++i) {
		if (s[i] == t[i]) {
			continue;
		}
		bool ok = false;
		for (int j = i + 1; j < n; ++j) {
			if (s[j] == s[i]) {
				answer.emplace_back(j, i);
				swap(s[j], t[i]);
				ok = true;
				break;
			}
			if (t[j] == t[i]) {
				answer.emplace_back(i, j);
				swap(s[i], t[j]);
				ok = true;
				break;
			}
		}
		if (!ok) {
			for (int j = i + 1; j < n; ++j) {
				if (s[j] == t[i]) {
					swap(s[j], t[j]);
					answer.emplace_back(j, j);
					swap(s[i], t[j]);
					answer.emplace_back(i, j);
					ok = true;
					break;
				}
				if (t[j] == s[i]) {
					swap(s[j], t[j]);
					answer.emplace_back(j, j);
					swap(t[i], s[j]);
					answer.emplace_back(j, i);
					ok = true;
					break;
				}
			}
		}
		if (!ok) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	cout << answer.size() << '\n';
	for (auto x : answer) {
		cout << x.first + 1 << ' ' << x.second + 1 << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(20);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
