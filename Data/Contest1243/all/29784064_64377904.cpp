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

void test_case() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<pair<char, char>> diff;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            diff.emplace_back(s[i], t[i]);
        }
    }
    if ((int) diff.size() == 2) {
        if (diff[0].first == diff[1].first && diff[0].second == diff[1].second) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        test_case();
    }
    return 0;
}
