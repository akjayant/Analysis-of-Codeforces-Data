#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define watch(x) cout << (#x) << " is: " << (x) << endl
#define vw(v)                        \
    cout << (#v) << " is: " << endl; \
    for (long long B : (v))          \
    {                                \
        cout << B << " ";            \
    }                                \
    cout << endl
#define check(x) cout << "here " << (x) << "?" << endl
#define rep(i, a, b) for (long long i = (a); i < (b); i++)
#define per(i, a) for (long long i = (a - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define rv(x) (x).rbegin(), (x).rend()
#define pb push_back
long long const MAX = 2147483647, REALMAX = 9223372036854775806;
set<long long> s;
map<pair<long long, long long>, long long> M;
void dfs(long long curr)
{
    vector<long long> vals;
    for (long long i : s)
    {
        if (M[{curr, i}] == 0)
        {
            vals.pb(i);
        }
    }
    for (long long i : vals)
    {
        s.erase(i);
    }
    for (long long i : vals)
    {
        dfs(i);
    }
}
int main()
{
    FAST_IO
    long long n, m, a, b, sum = 0, V;
    cin >> n >> m;
    rep(i, 1, n + 1)
    {
        s.insert(i);
    }
    rep(i, 0, m)
    {
        cin >> a >> b;
        M[{b, a}] = 1;
        M[{a, b}] = 1;
    }
    rep(i, 1, n + 1)
    {
        if (s.size())
        {
            V = *s.begin();
            s.erase(V);
            dfs(V);
            sum++;
        }
        else break;
    }
    sum--;
    cout << sum;
}