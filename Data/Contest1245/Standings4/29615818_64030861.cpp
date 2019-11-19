#include<bits/stdc++.h>				//Written by ThiDaiLoc
using namespace std;				//Team Three Wolves
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> triple;
typedef vector<ll> vi;
typedef vector<pll> vp;

#define fu(i,a,b)   for(ll i=a;i<=b;i++)
#define f1(i,n)     for(ll i=1;i<=n;i++)
#define fs(i,s)     for(ll i=0;i+1<=s.length();i++)
#define fd(i,b,a)   for(ll i=b;i>=a;i--)
#define fuv(i,a)    for(ll i=0;i<a.size();i++)
#define fdv(i,a)    for(ll i=(ll)a.size()-1;i>=0;i--)
#define ms(a,x)     memset(a, x, sizeof a)
#define prec(n)     fixed<<setprecision(n)
#define uni(a)      (a).erase(unique(all(a)), (a).end())
#define pb(i)       push_back(i)
#define popb()      pop_back()
#define sc(a)       cin>>a
#define sc2(a,b)    cin>>a>>b
#define pr(a)       cout<<a<<endl
#define pr2(a,b)    cout<<a<<" "<<b<<endl
#define rpr(a)      return cout<<a<<endl,0
#define prY         cout<<"YES"<<endl
#define prN         cout<<"NO"<<endl
#define bit(n,i)    (((n)>>(i))&1)
#define lowb(a,n,x) lower_bound(a,a+n,x) -a
#define lowb2(a,x)  lower_bound(all(a),x) -a.begin()
#define all(x)      (x).begin(), (x).end()
#define sz(a)       (ll)a.size()
#define le(s)       (ll)s.length()		
#define ast(x,a,b)  assert(x>=a and x<=b)				
#define re          return 	
#define	mp(a,b)     make_pair(a,b)
#define se          second
#define fi          first 
#define debug(x)    cerr << #x << " = " << x << endl
#define INPUT       freopen("locin.txt", "r", stdin)
#define OUTPUT      freopen("locout.txt", "w", stdout)
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline ll mnz(ll& a,ll b){return a=(a>b?b:a);}
inline ll mxz(ll& a,ll b){return a=(a<b?b:a);}
inline string toString(ll n) {stringstream ss; ss << n;return ss.str();}
double const eps = 1e-6;
ll const Base=1e9+7,oo=1e17,MAXN=1e6;


pll P[MAXN+5],Aans[MAXN+5];
class cmppq{
	public: bool operator()(triple a,triple b){
		re a.fi>b.fi;
	}
};
ll A[MAXN+5],B[MAXN+5],C[MAXN+5];

ll inline dis(ll u,ll v){
	re (abs(P[u].fi-P[v].fi)+abs(P[u].se-P[v].se))*(B[u]+B[v]);
}
bitset<MAXN+5> bi;
ll Solves(){
	
	ll n,m,k,cnt=0,ans=0,x,y,q,c,sum=0,v,t;
	// PROCESS IN HERE
	sc(n);
	f1(i,n)sc2(P[i].fi,P[i].se),C[i]=oo;
	priority_queue<triple,vector<triple>,cmppq> pq;
	f1(i,n)sc(A[i]),pq.push(mp(A[i],mp(i,0)));
	f1(i,n)sc(B[i]);
	while(cnt<n){
		triple X=pq.top();pq.pop();
		if(bi[X.se.fi])continue;
		bi[X.se.fi]=1;
		Aans[X.se.fi]=mp(X.se.se,X.fi);
		sum+=X.fi;
		cnt++;
		f1(i,n){
			if(i==X.se.fi)continue;
			if(bi[i])continue;
			v=dis(i,X.se.fi);
			if(v>=C[i])continue;
			C[i]=v;
			pq.push(mp(v,mp(i,X.se.fi)));
		}
	}
	pr(sum);
	vi v1;
	vp v2;
	f1(i,n){
		if(Aans[i].fi==0)v1.pb(i);
		else v2.pb(mp(i,Aans[i].fi));
	}
	pr(sz(v1));
	fuv(i,v1)cout<<v1[i]<<" ";
	pr("");
	pr(sz(v2));
	fuv(i,v2)cout<<v2[i].fi<<" "<<v2[i].se<<endl;
	re 0;
	// Hack it if you can :)
}

int main(){
	//INPUT;
	if(fopen("locin.txt", "r"))INPUT;
	ll JUDGE_ONLINE = 1;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll test=1;
//	sc(test);
	fu(T,1,test){
//		cout<<"Case #"<<T<<": ";
		Solves();
	}
	if (!JUDGE_ONLINE) cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";  
		
}
