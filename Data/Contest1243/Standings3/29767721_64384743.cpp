// <copy-paste>
#include<bits/stdc++.h>
#define FOR(i,s,e) for(int i=(s);i<=(e);i++)
#define FORD(i,s,e) for(int i=(s);i>=(e);i--)
#define eb emplace_back
#define MAXN 1000009
#define MOD 1000000007
#define mp(x, y) make_pair(x,y)
#define all(v) (v).begin(),(v).end()
#define pb(x) push_back(x)
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define pll pair <ll,ll>
using namespace std;

typedef unsigned long long LLU;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
const bool print=false;
typedef long long ll;

template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

int const N = 1e5 + 9;
int const maxn = 1e6 + 9;

ll n,m,k;

vector<int> adj[MAXN];

#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int a[MAXN];
int b[MAXN];
int c[MAXN];
int d[MAXN];
string s, t;
vector<PII> ans;
int dp[2][2][MAXN];
bool is(ll x){
    for(ll i = 2; i * i<= x;  i ++)
        if(x % i == 0)
            return 0;
    return x > 1;
}
int solve(){
    bool ok = 0;
    cin >> n;
    vector <ll>q;
    for(ll i = 2; i * i <= n; i ++)
    if(n % i == 0){
        while(n % i == 0)
            n/=i;
        if(q.size() > 0)
            return puts("1") * 0;
        q.push_back(i);
    }
    if(n > 1)
        q.push_back(n);
    if(q.size() == 1)
        n = q[0];
    else
        n = 1;
    cout << n;
}
int main()
{
    FAST;
    int t=1;
//    scanf("%d", &t);
//    cin >> t;
    while(t --){
        solve();
    }
}
//</copy-paste>
