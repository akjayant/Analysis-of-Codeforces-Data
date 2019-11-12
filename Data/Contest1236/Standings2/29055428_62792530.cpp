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
    int n; cin >> n;

    vector< vector<int> > ans(n, vector<int>(n));

    int bota = n * n;

    for(int j = 0; j<n; j++) {
        if(j&1) {
            for(int i = n-1; i>=0; --i) {
                ans[i][j] = bota--;
            }
        }
        else {
            for(int i = 0; i<n; i++) {
                ans[i][j] = bota;
                bota--;
            }
        }
    }

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) cout << ans[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}

/* don't forget to check:
   int overflow
   min/max cases (n = 1)
   printing index of sorted array
   limits for ans (start with inf)
 */
