#include <bits/stdc++.h>
 
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define INF  (1<<30)
#define INFL (1LL<<60)
#define EPS ((ld)(1e-9))
 
#define sz(x) ((int)(x).size())
#define setz(x) memset(x, 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define rep(i, e) for (int i = 0, _##i = (e); i < _##i; i++)
#define repp(i, s, e) for (int i = (s), _##i = (e); i < _##i; i++)
#define repr(i, s, e) for (int i = (s)-1, _##i = (e); i >= _##i; i--)
#define repi(i, x) for (auto &i : (x))
#define ARR(...) vector<int>({__VA_ARGS__})
#define ARS(...) vector<string>({__VA_ARGS__})
 
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<double> base;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
 
template<typename T, typename V>
ostream &operator<<(ostream &os, const pair<T, V> pai) { 
    return os << '(' << pai.first << ' ' << pai.second << ')';
}
 
template<typename T>
ostream &operator<<(ostream &os, const vector<T> v) {
    cout << '[';
    for (auto p : v) cout << p << ",";
    cout << "]";
    return os;
}
 
template<typename T, typename V>
ostream &operator<<(ostream &os, const set<T, V> v) {
    cout << "{";
    for (auto p : v) cout << p << ",";
    cout << "}";
    return os;
}
 
template<typename T, typename V>
ostream &operator<<(ostream &os, const map<T, V> v) {
    cout << "{";
    for (auto p : v) cout << p << ",";
    cout << "}";
    return os;
}
 
#ifndef __DJKIM613
#define debug(...) 0
#define endl '\n'
#else
#define debug(...) cout << " [-] ", _dbg(#__VA_ARGS__, __VA_ARGS__)
template<class TH> void _dbg(const char *sdbg, TH h){ cout << sdbg << '=' << h << endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
    while(*sdbg != ',') cout << *sdbg++;
    cout << '=' << (h) << ','; 
    _dbg(sdbg+1, a...);
}
#endif
 
template<typename T> void get_max(T &a, T b) {a = max(a, b);}
template<typename T> void get_min(T &a, T b) {a = min(a, b);}

const int MAXN = 1e5 + 10;
int test_case;
int N;
char S[MAXN];
char A[MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> test_case;
    while(test_case--){
        cin >> N;
        int a, b, c;
        cin >> a >> c >> b;

        cin >> S;

        int ans = 0;

        for(int i = 0 ; i <= N ; i++) A[i] = 0;
        for(int i = 0 ; i < N ; i++){
            if(S[i] == 'R' && c) A[i] = 'P', c--, ans++;
            if(S[i] == 'S' && a) A[i] = 'R', a--, ans++;
            if(S[i] == 'P' && b) A[i] = 'S', b--, ans++;
        }

        for(int i = 0 ; i < N ; i++) {
            if(A[i]) continue;
            if(a) A[i] = 'R', a--;
            else if(b) A[i] = 'S', b--;
            else A[i] = 'P', c--;
        }

        if((N + 1) / 2 <= ans) {
            cout << "YES\n";
            cout << A << '\n';
        }
        else cout << "NO\n";
    }

    return 0;
}