#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N ((int)1e5 + 1)
#define forn(i,x,y) for(int i = int(x); i<int(y); i++)
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(V) V.begin(), V.end()

template<typename T> ostream &operator<<(ostream &out, const pair<T, T> &P){ out << P.first << ' ' << P.second; return out; }
template<typename T> ostream &operator<<(ostream &out, const vector<T> &V){ for(int i = 0; i<V.size(); ++i) out << V[i] << ' '; return out; }
template<typename T> istream &operator>>(istream &in, vector<T> &V){ for(T &i : V) in >> i; return in; }
template<typename T> istream &operator>>(istream &in, pair<T,T> &P){ in >> P.first >> P.second; return in; }

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int q; cin >> q;
    while(q--) {

        int a, b, c; cin >> a >> b >> c;
        int ans = 0;
        while(c > 1 and b) {
            c -= 2;
            b--;
            ans += 3;
        }
        while(b > 1 and a) {
            b -= 2;
            a--;
            ans += 3;
        }
        cout << ans << '\n';
    }

    return 0;
}

/* don't forget to check:
   int overflow
   min/max cases (n = 1)
   printing index of sorted array
   limits for ans (start with inf)
 */
