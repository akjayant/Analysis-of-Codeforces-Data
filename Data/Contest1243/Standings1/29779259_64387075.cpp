#include <bits/stdc++.h>
#define FOR(i, u, v) for (int i = u; i <= v; i++)
#define FORD(i, v, u) for (int i = v; i >= u; i--)
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define mod 1000000007

using namespace std;

int n, cnt[100];
string s, t;
vector<pii> res;

bool solve() {
    FOR(i, 0, 'z' - 'a') cnt[i] = 0;
    FOR(i, 1, n) {
        cnt[s[i] - 'a']++;
        cnt[t[i] - 'a']++;
    }
    FOR(i, 0, 'z' - 'a')
        if (cnt[i] % 2) return 0;

    res.clear();
    FOR(i, 1, n) {
        if (s[i] == t[i]) continue;

        char c = s[i];
        FOR(j, i+1, n) {
            if (s[j] == c) {
                res.PB(mp(j, i));
                swap(s[j], t[i]);
                break;
            }
        }
        if (s[i] == t[i]) continue;
        FOR(j, i+1, n) {
            if (t[j] == c) {
                res.PB(mp(n, j));
                swap(s[n], t[j]);
                res.PB(mp(n, i));
                swap(s[n], t[i]);
                break;
            }
        }
        if (s[i] == t[i]) continue;
    }
    return 1;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("INP.TXT", "r")) {
		freopen("INP.TXT", "r", stdin);
    }
    int Tests; cin >> Tests;
    while (Tests--) {
        cin >> n >> s >> t;
        s = " " + s;
        t = " " + t;
        if (!solve()) cout <<"No"<<'\n';
        else {
            cout <<"Yes"<<'\n';
            cout <<res.size()<<'\n';
            for (auto z : res)
                cout <<z.F<<' '<<z.S<<'\n';
        }
    }
}

