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
int main()
{
    CIN;
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        string x, y;
        cin >> x >> y;
        vi v;
        rep(i,0,n){
            if(x[i]!=y[i]){
                v.pb(i);
            }
        }
        if(v.size()!=2){
            cout << "No\n";
        }else{
            if(x[v[0]] == x[v[1]]&&y[v[0]] == y[v[1]]){
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }
        }
    }
}