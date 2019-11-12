/*Bismillahir Rahmanir Rahim*///{
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ull = unsigned long long; using ld = long double;
const ll llinf = (1ll<<61)-1;
const double eps = 1e-6, ldeps = 1e-9;
struct Dbg {
static constexpr auto &os = cout;   // replace by cerr in interactive.
template<class C> static auto dud(C *x)->decltype(os << *x, 0);
template<class C> static char dud(...);
template<class C> typename enable_if<sizeof dud<C>(0)!=1, Dbg&>::type operator<<(const C &x) { os << x; return *this; }
template<class C> Dbg &dump(C b, C e) {
    *this << "\n[";
    int cur = 0;
    for (C i = b; i!=e and cur<26; i++, cur++) *this << ", "+2*(i==b) << *i;
    return *this << ']';
}
template<class C> typename enable_if<sizeof dud<C>(0)==1, Dbg&>::type operator<<(const C &x) {
    return dump(begin(x), end(x));
}
template<class C, size_t X> typename enable_if<sizeof(C)!=1, Dbg&>::type operator <<(C (&x)[X]) {
    return dump(begin(x), end(x));
}
template<class B, class C> Dbg &operator <<(const pair<B, C> &x) {
    return *this << '{' << x.first << ", " << x.second << '}';
}
template<class C, size_t Y> struct TP {
    void operator()(Dbg& os, const C &t) { TP<C, Y-1>()(os, t); os << ", " << get<Y-1>(t); }
};
template<class C> struct TP<C, 1> { void operator()(Dbg& os, const C &t) { os << get<0>(t); } };
template<class... C> Dbg& operator<<(const tuple<C...> &t) {
    os << '{', TP<decltype(t), sizeof...(C)>()(*this, t); return *this << '}';
}
Dbg &operator<<(ostream&(*x)(std::ostream&)) { os << x; return *this; }
} dbg;
void err(istringstream *iss) { delete iss; }
template<class C, class... Args> void err(istringstream *iss, const C &val, const Args &... args) {
    string name; *iss >> name; if (name.back()==',') name.pop_back();
    dbg << name << " = " << val << "; ", err(iss, args ...);
}
#define bug(args...) dbg << __LINE__ << ": ", err(new istringstream(string(#args)), args), dbg << endl
#define sl(a) int(strlen(a))
#define sz(a) int(a.size())
int T, Q, cn;//}
const int inf = 1000000007, mxn = 55;

char s[mxn], t[mxn];
int n, cnt[mxn];
pair<int, int> swaps[mxn<<1|1];
int si;

signed main() { ios::sync_with_stdio(0); cin.tie(NULL); cout.precision(11);
    cin >> T;
    while (cn++!=T) {
        cin >> n >> s >> t;
        for (int i = 0; i < n; i++) {
            cnt[s[i]-'a']++, cnt[t[i]-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i]&1) {cout << "No\n"; goto x;}
        }
        for (int i = 0; i < n; i++) {
            if (s[i]==t[i]) {
                continue;
            }
            bool ok = 0;
            for (int j = i+1; j <= n-1; j++) {
                if (t[j]!=t[i]) continue;
                ok = 1;
                swap(s[i], t[j]);
                swaps[si++] = {i+1, j+1};
                break;
            }
            if (!ok) {
                for (int j = i+1; j <= n-1; j++) {
                    if (s[j]!=t[i]) continue;
                    ok = 1;
                    swap(s[j], t[j]);
                    swaps[si++] = {j+1, j+1};
                    swap(s[i], t[j]);
                    swaps[si++] = {i+1, j+1};
                    break;
                }
                // if (!ok) {cout << "No\n"; goto x;}
                assert(ok);
            }
        }
        assert(!strcmp(s, t));//bug(s, t);
        cout << "Yes\n";
        cout << si << '\n';
        for (int i = 0; i < si; i++) {
            cout << swaps[i].first << ' ' << swaps[i].second << '\n';
        }
        x :;
        memset(cnt, 0, sizeof(cnt));
        si = 0;
    }
}