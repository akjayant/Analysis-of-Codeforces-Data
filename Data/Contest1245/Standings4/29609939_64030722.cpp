#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define zy -2147382637
#define bql 2147483647
#define ll long long
#define ull unsigned long long
#define ld long double
#define il inline
#define sz(x) x.size()
#define maxn 2010
#define rp(i, l, r) for (int i = l; i <= r; i++)
#define rb(i, r, l) for (int i = r; i >= l; i--)
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;
ll max(ll a,ll b){if(a>b)return a;else return b;}
ll min(ll a,ll b){if(a<b)return a;else return b;}
ll lowbit(ll x){return x&(-x);}
ll prime(ll x){
   if(x<=1)return false;
   for(int i=2;i<=int(sqrt(x));i++){
	   if(x%i==0)return false;
   }return true;
}
bool cmp(ll a,ll b){return a>b;}
ll gcd(ll a,ll b){ll r;while(b>0){r=a%b;a=b;b=r;}return a;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
inline ll read() {
	char c = getchar(); ll w = 1; ll x = 0;
	while (!isdigit(c))
		(c == '-') && (w = -w), c = getchar();
	while (isdigit(c))
		x = (x << 1) + (x << 3) + (c ^ '0'), c = getchar();
	x *= w;
}
const int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1},
		  dy[8] = {0, 0, -1, 1, -1, -1, 1, 1};
ll n,x[maxn],y[maxn],g[maxn],k[maxn],d1[maxn],d2[maxn],vis[maxn],tit[maxn],ans=0;
vector<ll> s1;
vector<pair<ll,ll> >s2;
int main()
{
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>x[i]>>y[i];
    for(ll i=1;i<=n;i++){
       cin>>g[i];d1[i]=g[i],d2[i]=1e17;
   	}
    for(ll i=1;i<=n;i++)cin>>k[i];
    for(ll i=1;i<=n;i++)
    {
        ll minv=1e17,flag=0;
        for(ll j=1;j<=n;j++){
            if(!tit[j]&&minv>min(d1[j],d2[j]))minv=min(d1[j],d2[j]),flag=j;
        }
        if(!flag)break;
        tit[flag]=1;ans+=minv;
        if(d1[flag]<d2[flag])s1.push_back(flag);
        else s2.pb(mp(flag,vis[flag]));
        for(ll j=1;j<=n;j++)
        {
            if(!tit[j]){
    			ll va=(abs(x[j]-x[flag])+abs(y[j]-y[flag]))*(k[j]+k[flag]);
                if(va<d2[j]){
					d2[j]=va;
					vis[j]=flag;
				}
            }
        }
    }
    cout<<ans<<endl<<s1.size()<<endl;
    for(ll i=0;i<s1.size();i++)
        cout<<s1[i]<<' ';
    cout<<endl<<s2.size()<<endl;
    for(ll i=0;i<s2.size();i++)cout<<s2[i].fi<<' '<<s2[i].se<<endl;
	return 0;
}
