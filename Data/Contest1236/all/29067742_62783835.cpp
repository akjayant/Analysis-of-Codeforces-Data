#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <ctime>
#include <complex>
//#include <random>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define forn(i,n) for(int i = 0;i<n;i++)
#define for1(i,n) for(int i = 1;i<=n;i++)

#define pb push_back
//#define mp make_p/**/air
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<string,string> PSS;

typedef unsigned us;
typedef unsigned int ui;
typedef unsigned long long ull;
const ll mod=1e9+7;
const ll MOD=123456789;
const ll inf = 2e18;
const int maxn = 300005;
const int maxm = 500005;
ll printArray(ll a[],int t){cout<<"[";for(int i = 0;i<t;i++){cout<<a[i];if(i!=t-1)cout<<", ";}cout<<"]"<<endl;return 0;}
ll printArray(int a[],int t){cout<<"[";for(int i = 0;i<t;i++){cout<<a[i];if(i!=t-1)cout<<", ";}cout<<"]"<<endl;return 0;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; if(b<0) return -1; for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
//ll powmod2(ll a,ll b) {ll res=1;a%=MOD; if(b<0) return -1; for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll inv_mod(ll a){return powmod(a,mod-2);}



int main()
{
    ios::sync_with_stdio(0);

    int T;
    cin>>T;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        int ans = 0;
        int t = min(b, c/2);
        ans += 3 * t;
        b-=t;
        t = min(a,b/2);
        ans += 3 * t;
        cout<<ans<<endl;
    }

    return 0;
}



















