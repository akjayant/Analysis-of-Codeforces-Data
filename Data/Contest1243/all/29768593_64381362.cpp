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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector <int> p;
        for(int i = 0; i < n; i++)
        {
            if(s[i] != t[i])
                p.pb(i);
        }
        if(!p.empty() and (p.size() != 2 or s[p[0]] != s[p[1]] or t[p[0]] != t[p[1]]))
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}
