#include <bits/stdc++.h>
using namespace std;

#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define in_range(x,l,r) (lb(all(x),r+1)-lb(all(x),l))
#define per(i,n) for (int i=(int)(n)-1;i>=0;i--)
#define For(i,n) for (int i=1;i<=(int)(n);i++)
#define Rep(i,n) for (int i=0;i<=(int)(n);i++)
#define rep(i,n) for (int i=0;i<(int)(n);i++)
#define set0(i) memset(i,0,sizeof(i))
#define all(x) (x).begin(),(x).end()
#define Max(a,b,c) max(a,max(b,c))
#define Min(a,b,c) min(a,min(b,c))
#define fore(i,x) for (auto &i:x)
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
#define pii pair<int,int>
#define vi vector <int>
#define lb lower_bound
#define ub upper_bound
#define ll long long
#define pb push_back
#define re return
#define se second
#define fi first
const int INF=0x7fffffff;
const int MAXN=2000+3;

#define int long long
int n,mn[MAXN];
int c[MAXN],k[MAXN],x[MAXN],y[MAXN];
bool ok[MAXN];
vi ps;
vector <pii> e;
ll ans;
priority_queue <pair<pii,int>,vector<pair<pii,int> >, greater<pair<pii,int> > > q; 

signed main(){
	fio;
	cin>>n;
	For(i,n){
		cin>>x[i]>>y[i];
	}
	For(i,n){
		cin>>c[i];
		q.push({{c[i],i},-1});
		mn[i]=c[i];
	}
	For(i,n){
		cin>>k[i];
	}
	while (q.size()){
		int d=q.top().fi.fi,x=q.top().fi.se,frm=q.top().se;
		q.pop();
		if (ok[x]) continue;
		if (frm==-1){
			ps.pb(x);
		}else{
			e.pb({frm,x});
		}
		ok[x]=1;
		ans+=d;
		For(i,n){
			if (ok[i]) continue;
			ll cst=(abs(::x[x]-::x[i])+abs(y[x]-y[i]))*(k[x]+k[i]);
			if (cst<(ll)mn[i]){
				q.push({{cst,i},x});
				mn[i]=cst;
			}
		}
	}
	cout<<ans<<endl<<ps.size()<<endl;
	fore(i,ps){
		cout<<i<<" ";
	}
	cout<<endl;
	cout<<e.size()<<endl;
	fore(i,e){
		cout<<i.fi<<" "<<i.se<<endl;
	}
	re 0;
}