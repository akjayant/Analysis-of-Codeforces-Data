#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1 << 30;
const ll LINF = 1LL << 62;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int cnt = 0;
        vector <int> v;
        for(int i = 0; i < n; i++) {
            if(s[i] != t[i]) cnt++, v.eb(i);
        }
        if(cnt == 2) {
            if(s[v[0]] == s[v[1]] && t[v[0]] == t[v[1]]) cout << "Yes\n";
            else cout << "No\n";
        }
        else if(cnt == 0) cout << "Yes\n";
        else cout << "No\n";
    }
}