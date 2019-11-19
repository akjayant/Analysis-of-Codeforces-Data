#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define uld unsigned long double
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define vii vector<int>
#define vll vector<ll>
#define vdd vector<double>
#define sii set<int>
#define sll set<ll>
#define sdd set<double>
#define x first
#define y second
#define pb push_back
#define ins insert
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define allo(x, n) (x),(x) + (n)
#define feach(i, a) for(auto &i : a)
#define file(x) freopen(string(string((x)) + ".in").c_str(), "r", stdin); freopen(string(string((x)) + ".out").c_str(), "w", stdout);

const double PI = acos(-1);
const ll INF = 1e18;
const int MAXN = 1e5 + 1;

ll calc(int n, vii d)
{
    int col[n] = {0};
    bool used[n] = {0};
    int cnt = 0;
    while(1)
    {
        int p = 0;
        while(p < n and col[p]) p++;
        if(p == n) break;
        cnt++;

        col[p] = cnt;
        while(1)
        {
            int p1 = p;
            while(p1 < n and (col[p1] != cnt or used[p1])) p1++;
            if(p1 == n) break;
            used[p1] = 1;
            feach(i, d)
            {
                if(i <= p1)
                    col[p1 - i] = cnt;
                if(p1 + i < n)
                    col[p1 + i] = cnt;
            }
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    int t;
//    cin >> t;
//    while(t--)
//    {
//        int n;
//        cin >> n;
//        string s, t;
//        cin >> s >> t;
//        vector <int> p;
//        for(int i = 0; i < n; i++)
//        {
//            if(s[i] != t[i])
//                p.pb(i);
//        }
//        if(!p.empty() and (p.size() != 2 or s[p[0]] != s[p[1]] or t[p[0]] != t[p[1]]))
//            cout << "NO\n";
//        else
//            cout << "YES\n";
//    }

    ll n;
    cin >> n;
    vll d;
    for(ll i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            d.pb(i);
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1)
        d.pb(n);
    if(d.size() == 1)
        cout << d[0];
    else
        cout << 1;

    return 0;
}
