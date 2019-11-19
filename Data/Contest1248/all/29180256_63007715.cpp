//sieunhan
#include <bits/stdc++.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd
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
int x,n,res,res1=1,res2=1,tong[oo];
pii a[oo];
string s;
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
	cin>>n>>s;
}
int tinh(string s){
	for(int i=1;i<n*2;++i) tong[i]=(s[i]!='(' ? -1 : 1)+tong[i-1] ;
	if(0!=tong[n]) return 0;
	int l=1,r=0,ans=0,dem=0;
	for(int i=1;i<=n;++i){
		while(r>=l && tong[i]<=a[r].fi){
			--r;
		}
		a[++r]={tong[i],i};
	}
	if(0<=a[l].fi) ++ans;
	for(int i=1+n;i<n*2;++i){
		while(r>=l && n+a[l].se<=i){
			++l;
		}
		while(r>=l && tong[i]<=a[r].fi){
			--r;
		}
		dem+=(s[i-n]!='(' ? 1 : -1);
		if(-dem<=a[l].fi) ++ans;
		a[++r]={tong[i],i};
	}
	return ans;
}
void xuly(){
	s="*"+s+s;
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			swap(s[j],s[i]);
			swap(s[n+j],s[n+i]);
			x=tinh(s);
			if(res<=x){
				res2=j;
				res1=i;
				res=x;
			}
			swap(s[j],s[i]);
			swap(s[n+j],s[n+i]);
		}
	}
	cout<<res<<xd<<res1<<" "<<res2;
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
