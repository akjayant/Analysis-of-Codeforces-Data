#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define display(v) for (auto x : v) cout << x << ", "
#define print(x) cout << (#x) << " = [ ";display(x); cout << "]\n"
#define endl '\n'
#define pb push_back
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
 
// DEBUG TEMPLATE by livw
void __print(int x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifdef INCLUDEWHENOFFLINE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


int main()
{
    fastio;
    
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        ll ac, bc, cc;
        cin >> a >> b >> c;
        ac = a, bc = b, cc = c;
        ll m = min(a, b / 2);
        ll ans = 3 * m;
        a -= m;
        b -= m * 2;
        m = min(b, c / 2);
        ans += 3 * m;
        a = ac, b = bc, c = cc;
        ll temp = 0;
        m = min(b, c / 2);
        temp += 3 * m;
        b -= m;
        m = min(a, b / 2);
        temp += 3 * m;
        cout << max(ans, temp) << endl;
    }
    return 0;
}


