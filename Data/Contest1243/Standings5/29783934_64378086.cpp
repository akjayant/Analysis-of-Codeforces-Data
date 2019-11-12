#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

#define C continue;
#define R return;

#define I insert
#define D double

#define ull unsigned long long int
#define ll long long int
#define ui unsigned int
#define ld long double
#define pb push_back
#define pf push_front

#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vb vector<bool>
#define vd vector<D>
#define vll vector<ll>
#define vull vector<ull>
#define vld vector<ld>

#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vvc vector<vector<char>>
#define vvll vector<vector<ll>>
#define vvd vector<vector<D>>
#define vvld vector<vector<ld>>

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pull pair<ull, ull>
#define pld pair<ld, ld>
#define pdd pair<D, D>

#define vpld vector<pld>
#define vpii vector<pii>
#define vpll vector<pll>
#define vpdd vector<pdd>

#define vvpii vector<vector<pii>>
#define vvpll vector<vector<pll>>

#define PQ(type) priority_queue<type>
#define PQD(type) priority_queue<type, vector<type>, greater<type>>

#define mii map<int, int>
#define mll map<ll, ll>
#define mci map<char, int>
#define msi map<string, int>
#define mis map<int, string>

#define umii unordered_map<int, int>
#define umll unordered_map<ll, ll>
#define umci unordered_map<char, int>
#define umsi unordered_map<string, int>
#define umis unordered_map<int, string>

#define dist(a, b, p, q) sqrt((p - a) * (p - a) + (q - b) * (q - b))

#define pp(n) printf("%.10Lf", n);
#define line cout << "\n";

#define mod1 1000000007
#define mod2 998244353 
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define loop(i, a, b) for (int i = a; i < b; i++)
#define loopr(i, a, b) for (int i = a; i >= b; i--)
#define loops(i, a, b, step) for (int i = a; i < b; i += step)
#define looprs(i, a, b, step) for (int i = a; i >= b; i -= step)
#define P pair
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie();                        \
    cout.tie();
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define endl "\n"
#define f(i, n) for (ll i = 0; i < n; i++)
#define ff(i, n) for (ll i = 1; i <= n; i++)
#define pb push_back
#define eb emplace_back
#define bgn(x) ((x).begin())
#define sz(x) ((x).size())
#define in1(x, n) f(i, n) cin >> x[i];
#define in2(x, n, m) f(i, n) f(j, m) cin >> x[i][j];
#define out1(x, n)               \
    f(i, n) cout << x[i] << " "; \
    cout << "\n";
#define out2(x, n, m)                       \
    f(i, n) {f(j, m) cout << x[i][j] << " "; \
    cout << "\n";}
#define fir(x, y) f(int i = min(x, y); i <= max(x, y); i++)
#define firr(x, y) f(int i = max(x, y); i <= min(x, y); i++)
#define imin INT_MIN
#define imax INT_MAX
#define lmax LLONG_MAX
#define lmin LLONG_MIN
#define dmin DBL_MIN
#define dmax DBL_MAX

#define mxt(a) *(max_element(a.begin(), a.end()))
#define mnt(a) *(min_element(a.begin(), a.end()))
#define mem(x, val) memset(x, val, sizeof(x))
#define prfloat(val, precise) cout << fixed << setprecision(precise) << val << endl;
#define dbg1(x) cout << " > " << #x << " = " << x << "\n";
#define dbg2(x, y) cout << " < " << #x << " = " << x << ", " << #y << " = " << y << endl;
#define count_1(n) __builtin_popcountll(n)
#define sqr(x) ((x) * (x))
#define inrange(i, a, b) ((i >= min(a, b)) && (i <= max(a, b)))

const ll maxn = 1e5+5;
const ll inf = 1e9;
const long double PI = acos(-1);

void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
ll pmod(ll a,ll mod=mod1) { return ((a) % mod + mod) % mod; }
ll cel(ll x1, ll y1) //not for negative x1
{
    if((x1)<=0){
        return (x1)/(y1);
    }
    return (((x1) / (y1)) + (((x1) % (y1)) != 0));
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

long long bp(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

long long bpm(long long a, long long b, long long m=mod1)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res % m;
}

string vow = "aeiou";

const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};

const int dx8[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy8[] = {0, 1, 0, -1, -1, 1, -1, 1};

const int dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyhorse[] = {1, -1, 2, -2, 2, -2, 1, -1};

void solve(){
int k;
cin>>k;
while(k--){
    int n;
    cin >> n;
    string s,t;
    cin>>s>>t;
    int cnt = 0;
    int idx1 = -1, idx2 = -1;
    for (int i = 0; i < n;i++){
        if(s[i]!=t[i]){
            cnt++;
            if(cnt==2) idx2=i;
            else if(cnt==1)
                idx1 = i;
        }
    }
    if(cnt==0){
        cout << "Yes\n";
    }
    else if(cnt!=2) {
        cout << "No\n";
    }
    else{
        if(s[idx1]==s[idx2] && t[idx1]==t[idx2]){
            cout << "Yes\n";
        }
        else
            cout << "No\n";
    }
}
}

int main()
{
    fast;
    int t = 1;
    //cin >> t;
    while (t--)
    {

        solve();
        line
    }

    return 0;
    }