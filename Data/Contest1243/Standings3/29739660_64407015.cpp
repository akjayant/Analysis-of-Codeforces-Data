/*
 _____ ____ _____   ___   ___   ___   ___ 
|_   _/ __ \_   _| |__ \ / _ \ |__ \ / _ \
  | || |  | || |      ) | | | |   ) | | | |
  | || |  | || |     / /| | | |  / /| | | |
 _| || |__| || |_   / /_| |_| | / /_| |_| |
|_____\____/_____| |____|\___/ |____|\___/ 
*/
#include <bits/stdc++.h>
#define rep(i, a, b) for (long long i = (a); i < (b); i++)
#define per(i, a, b) for (long long i = (a); i > (b); i--)
#define a(x) (x.begin(), x.end())
#define ar(x) (x.rbegin(), x.rend())
#define pb push_back
#define Pb() pop_back()
#define ll long long int
#define ull unsigned long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sc scanf
#define scin(x) sc("%d", &(x))
#define scln(x) sc("%lld", &(x))
#define pf prllf
#define ms(a, b) memset(a, b, sizeof(a))
#define mp make_pair
#define db double
#define EPS 10E-10
#define ff first
#define ss second
#define sqr(x) (x) * (x)
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define DBG pf("HI\n")
#define MOD 1000000007
#define CIN                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define RUN_CASE(t, T) for (__typeof(t) t = 1; t <= T; t++)
#define CASE(t) prllf("Case %d: ", t)
#define CASEL(t) prllf("Case %d:\n", t)
#define intlimit 2147483647
#define longlimit 9223372036854775807
#define infinity (1 << 28)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a) * (b) / gcd(a, b))
#define PI 2 * acos(0.0)
using namespace std;
map<pair<int, int>, int> m;
set<int> s;
void dfs(int curr)
{
    vi vals;
    for (int i : s)
        if (m[{curr, i}] == 0)
            vals.pb(i);
    for (int i : vals)
        s.erase(i);
    for (int i : vals)
        dfs(i);
}

int main()
{
    CIN;
    int n, k;
    cin >> n >> k;
    rep(i, 1, n + 1)
        s.insert(i);
    rep(i, 0, k)
    {
        int a, b;
        cin >> a >> b;
        m[{a, b}] = 1;
        m[{b, a}] = 1;
    }
    int klo = 0;
    rep(i, 1, n + 1)
    {
        if (s.size())
        {
            int v = *s.begin();
            s.erase(v);
            dfs(v);
            klo++;
        }
        else
            break;
    }
    cout << klo - 1;
}