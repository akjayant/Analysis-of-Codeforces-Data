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

int main() {
	#ifdef LOCAL
	freopen("in", "r", stdin);
	#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
    	int n, a, b, c;
    	cin >> n >> a >> b >> c;
    	string str;
    	cin >> str;
    	map<char, char> lose = {{'R','S'}, {'P', 'R'}, {'S', 'P'}}, win;
    	map<char, int> cnt = {{'R', a}, {'P', b}, {'S', c}};
    	for (auto e : lose) {
    		win[e.second] = e.first;
    	}
    	vector<char> ans(n);
    	int cntwin = 0;
    	for (int i = 0; i < n; i++) {
    		if (cnt[win[str[i]]]) ++cntwin, ans[i] = win[str[i]], --cnt[win[str[i]]];
    	}
    	for (int i = 0; i < n; i++) {
    		if (ans[i] == 0) {
    			if (cnt[str[i]]) --cnt[str[i]], ans[i] = str[i];
    			else --cnt[lose[str[i]]], ans[i] = lose[str[i]];
    		}
    	}
    	if (cntwin >= (n + 1) / 2) {
    		cout << "YES\n";
    		for (auto e : ans) cout << e;
    		cout << endl;
    	} else cout << "NO\n";
    }
    return 0;
}