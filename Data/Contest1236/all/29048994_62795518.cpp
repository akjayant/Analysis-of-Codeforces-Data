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
const int oo=3e2+5,inf=1e17,mod=1e9+7;
int test;
int n,x,y;
vi v[oo];
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
}
void xuly(){
	for(int i=1;i<=n;++i){
		if(0==y) for(int j=n;j>0;--j) v[j].pb(++x);
		else for(int j=1;j<=n;++j) v[j].pb(++x);
		y=1^y;
	}
	for(int i=1;i<=n;++i){
		for(auto k : v[i]) cout<<k<<" ";
		cout<<xd;
	}
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
