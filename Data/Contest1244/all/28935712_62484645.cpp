//sieunhan
#include <bits/stdc++.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd
#define int long long
#define double long double
#define inp "test.inp"
#define out "test.out"
#define ms(x,y) memset(x,y,sizeof(x))
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define prec(n) fixed<<setprecision(n)
#define xd '\n'
#define pii pair<int,int>
#define dq deque<int>
#define vi vector<int>
#define li list<int>
#define si set<int>
#define ma map<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define y1 hungdzno1
const int oo=1e5+5,inf=1e17,mod=1e9+7;
int test;
int n,xp,cha[oo],tv[oo],a[5][oo],f[5][5][oo];
vi ke[oo];
int doc(){
	char ch=getchar();
  int x=0,ff=1;
	while(ch<'0' || ch>'9'){
    if(ch=='-') ff=-ff;
    ch=getchar();
  }
	while(ch>='0' && ch<='9'){
    x=x*10+ch-'0';
    ch=getchar();
  }
	return x*ff;
}
void viet(int x){
	if(x<0){
    putchar('-');
    x=-x;
  }
	if(x>9) viet(x/10);
	putchar(x%10+'0');
	return;
}
void nhap(){
	cin>>n;
	for(int i=1;i<4;++i) for(int j=1;j<=n;++j) cin>>a[i][j];
}
void dfs(int x,int y){
	for(auto v : ke[x]){
		if(y!=v){
			cha[x]=v;
			dfs(v,x);
		}
	}
}
int tinh(int x,int i,int j){
	if(!x) return 0;
	if(f[i][j][x]>=0) return f[i][j][x];
	int ans=inf;
	for(int k=1;k<4;++k) if(j!=k && i!=k) ans=min(ans,tinh(cha[x],j,k)+a[k][x]);
	return f[i][j][x]=ans;
}
void truy(int x,int i,int j){
	if(!x) return;
	for(int k=1;k<4;++k){
		if(j!=k && i!=k){
			if(tinh(cha[x],j,k)+a[k][x]==tinh(x,i,j)){
				tv[x]=k;
				truy(cha[x],j,k);
				return;
			}
		}
	}
}
void xuly(){
	for(int i=1;i<n;++i){
		int x,y;
		cin>>x>>y;
		ke[x].pb(y);
		ke[y].pb(x);
	}
	for(int i=1;i<=n;++i){
		int z=ke[i].size();
		if(1==z) xp=i;
		else{
			if(2<z){
				cout<<-1;
				return;
			}
		}
	}
	dfs(xp,0);
	ms(f,-1);
	cout<<tinh(xp,0,0)<<xd;
	truy(xp,0,0);
	for(int i=1;i<=n;++i) cout<<tv[i]<<" ";
}
main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen(inp,"r",stdin);
  freopen(out,"w",stdout);
  #endif
	test=1;
	// cin>>test;
  while(test--){
		nhap();
		xuly();
	}
}
