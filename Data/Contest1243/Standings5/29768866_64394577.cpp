#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define OnlineJudgeYourMomGay ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set(data_type) tree<data_type, null_type, less<data_type>,rb_tree_tag, tree_order_statistics_node_update>
#define scl(x) scanf("%lld",&x)
#define sc(x) scanf("%d"  ,&x)
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define F first
#define S second

using namespace __gnu_pbds;
using namespace std;

using ll  = long long;
using ld  = long double;
using ii = pair<int,int>;
const int N = 3e5 + 600;
const long long mod = 1e9 + 7;
const ll inf = LLONG_MAX;

const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,-1,1};
void err(istream_iterator<string> it) {cerr << endl;}
template<typename T, typename... Args>void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;err(++it, args...);}
ll sums() { return 0; }template<typename... Args>ll sums(ll a, Args... args) { return a + sums(args...); }
int Max(){return INT_MIN;}template<typename... Args>int Max(int a,Args... args){return max(a,Max(args...));}
int Min(){return INT_MAX;}template<typename... Args>int Min(int a,Args... args){return min(a,Min(args...));}
ll  gcd(){return 0;}template<typename... Args>ll gcd(ll a, Args... args){return __gcd(a,gcd(args...));}
template<typename T> void _R(T &x){ cin >> x;}
//void _R(int &x) { scanf("%d", &x); }
//void _R(ll &x) { scanf("%lld", &x); }
//void _R(double &x) { scanf("%lf", &x); }
//void _R(char &x) { scanf(" %c", &x); }
//void _R(char *x) { scanf("%s", x); }
void read(){}
template<typename T,typename... Args>void read(T &a, Args&... args){_R(a);read(args...);}

bool isPrime(ll x){
    if(x == 2)return true;
    if(x == 1)return false;
    if(x%2 == 0)return false;
    for(ll i = 3; i *i <= x; ++i)if(x % i == 0)return false;
    return true;
}
int main()
{
    long long n;
    cin >> n;
    if(n == 1)return cout <<1 << '\n',0;
    if(isPrime(n))return cout << n << '\n',0;
    vector<ll>v;
    for(ll i = 2; i*i <= n; ++i){
        if(n % i == 0)v.push_back(i),v.push_back(n/i);
    }
    ll gcd = 0;
    for(auto i : v)gcd= __gcd(gcd,i);
    if(gcd == 1)cout << 1 << '\n';
    else cout << gcd << '\n';
    return 0;
}
