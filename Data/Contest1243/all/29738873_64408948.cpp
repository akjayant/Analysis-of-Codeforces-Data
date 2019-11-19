#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define de(x) cout<<#x<<" = "<<x<<"\n"
#define dd(x) cout<<#x<<" = "<<x<<" "
#define mes(p) memset(p,0,sizeof(p))
#define all(x) x.begin(),x.end()
#define rson mid+1,r,rt<<1|1
#define sz(x) (int)x.size()
#define mp make_pair 
#define lson l,mid,rt<<1
#define pb push_back
#define ls (rt<<1)
#define rs (ls|1)
#define se second
#define fi first
typedef pair <int ,int > pi;
typedef vector <int > vi;
const int maxn=2e5+5;
const int mod = 1e9+7;
typedef long long ll;
int f[maxn];
vi e[maxn];
int b[maxn], c[maxn];
vi v, t;
int find(int x){
	if(f[x]==x) return x;
	return f[x] = find(f[x]);
}
void uni(int x,int y){
	int xx= find(x);
	int yy=find(y);
	if(xx!=yy)
		f[xx] = yy; 
}
int main(){
	ios_base::sync_with_stdio(0);
   	cin.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i,0,m){
		int x, y;
		cin >> x>> y;
		e[x].pb(y);
		e[y].pb(x); 
	}
	rep(i,1,n+1) sort(all(e[i]));
	int mx = 1;
	rep(i,2,n+1)
		if(sz(e[i])<sz(e[mx])) mx = i;
	rep(i,1,n+1) f[i] =i;
	for(auto u:e[mx]) b[u] = 1;
	rep(i,1,n+1)
		if(!b[i]) v.pb(i), uni(i,mx);
		else t.pb(i);
	for(auto x:v){
		for(auto u:e[x])
			c[u]++;
	}
	rep(i,1,n+1)
		if(b[i] && c[i]!=sz(v))
			uni(i, mx);
	rep(i,0,sz(t)) rep(j,0,sz(t))
		if(i!=j){
			int x = t[i], y = t[j];
			if((*lower_bound(all(e[x]), y))!=y)
				uni(x, y);
		}
	int ans =0;
	rep(i,1,n+1)
		if(find(i)==i) ans++;
	cout << ans-1;
	return 0;
}
