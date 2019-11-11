#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const string RPS = "RPS";
int lose[3] = {1, 2, 0}; 
int win[3] = {2, 0, 1};

int main() {
	fastio;
	
    int ts; cin >> ts;
    while (ts--) {
        int n; cin >> n;
        int c_a[3]; forn(t, 3) cin >> c_a[t];

        vi b(n); forn(i, n) {char c; cin >> c; b[i] = RPS.find(c); }

        vi a(n, -1);
        int p = 0;

        forn(i, n) {
            int t2 = b[i];

            if (c_a[lose[t2]] > 0) {
                int t1 = lose[t2];
                c_a[t1]--;
                a[i] = t1;
                p++;
            }
        }

        forn(i, n) if (a[i] == -1) {
            int t2 = b[i];

            int t1 = c_a[t2] > 0 ? t2 : win[t2];
            c_a[t1]--;
            a[i] = t1;
        }

        if (2 * p >= n) {
            cout << "YES" << endl;
            forn(i, n) cout << RPS[a[i]];
            cout << endl;
        }
        else cout << "NO" << endl;
    }
	
	return 0;
}
