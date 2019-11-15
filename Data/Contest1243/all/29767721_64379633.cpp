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
int solve(){
    bool ok = 0;
    int n;
    cin >> n >> s >> t;
    if(s == t)
        return puts("Yes") * 0;
    int cnt = 0;
    vector <int> q;
    for(int i = 0; i < n; i ++)
        if(s[i] != t[i])
            q.push_back(i);
    if(q.size() != 2)
        return puts("No") * 0;
    if(s[q[0]] == s[q[1]] && t[q[0]] == t[q[1]])
        ok = 1;

    puts(ok ? "YES" : "NO");
}
int main()
{
    FAST;
    int t=1;
//    scanf("%d", &t);
    cin >> t;
    while(t --){
        solve();
    }
}
//</copy-paste>
