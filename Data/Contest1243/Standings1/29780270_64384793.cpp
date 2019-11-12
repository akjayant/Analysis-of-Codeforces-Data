#include<bits/stdc++.h>				//Written by ThiDaiLoc
using namespace std;				//Team Three Wolves
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> trp;
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
#define prY         cout<<"Yes"<<endl
#define prN         cout<<"No"<<endl
#define bit(n,i)    (((n)>>(i))&1)
#define lowb(a,n,x) lower_bound(a,a+n,x) -a
#define lowb2(a,x)  lower_bound(all(a),x) -a.begin()
#define all(x)      (x).begin(), (x).end()
#define sz(a)       (ll)a.size()
#define le(s)       (ll)s.length()		
#define ast(x,a,b)  assert(x>=a and x<=b)				
#define re          return 	
#define	mp(a,b)     make_pair(a,b)
#define	mp3(a,b,c)  make_pair(a,make_pair(b,c))
#define se          second
#define fi          first 
#define sse         second.second
#define sfi         second.first
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


ll A[MAXN+5];
vector<pll> compress(vi vec){
	sort(all(vec));
	vector<pll> v;
	ll cnt=1;
	fu(i,1,sz(vec)){
		if(i==sz(vec) or vec[i]!=vec[i-1]){
			v.pb(mp(vec[i-1],cnt));
			cnt=1;
		}
		else cnt++;
	}
	re v;
}
ll Solves(){
	
	ll n,m,k,cnt=0,ans=0,x,y,q,c,sum=0,v,t;
	// PROCESS IN HERE
	sc(n);
	string S,T;
	sc2(S,T);
	string S2=S+T;
	vi vv;
	fs(i,S2)vv.pb(S2[i]);
	vp v3=compress(vv);
	fuv(i,v3)if(v3[i].se%2)re prN,0;
	vp vec;
	fs(i,S){
		if(S[i]!=T[i]){	
		ll flag=0;
			fu(j,i+1,le(T)-1){
				if(T[j]==T[i]){
					swap(T[j],S[i]);
					vec.pb(mp(i+1,j+1));
					flag=1;
					break;
				}
			}
			if(!flag){
				fu(j,i+1,le(T)-1){
					if(T[j]==S[i]){
						swap(T[i],S[i]);
						vec.pb(mp(i+1,i+1));
						swap(T[j],S[i]);
						vec.pb(mp(i+1,j+1));
						flag=1;
						break;
					}
				}
			}
			if(!flag){
				fu(j,i+1,le(T)-1){
					if(S[j]==T[i]){
						swap(T[i],S[i]);
						vec.pb(mp(i+1,i+1));
						swap(S[j],T[i]);
						vec.pb(mp(j+1,i+1));
						flag=1;
						break;
					}
				}
			}
			if(!flag)assert(0);
		}
	}
	prY;
	pr(sz(vec));
	fuv(i,vec)cout<<vec[i].fi<<" "<<vec[i].se<<endl;
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
	sc(test);
	fu(T,1,test){
//		cout<<"Case #"<<T<<": ";
		Solves();
	}
	if (!JUDGE_ONLINE) cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";  
		
}
