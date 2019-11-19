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
int res,n,p,w,d;
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
	cin>>n>>p>>w>>d;
}
void xuly(){
	res=p/w;
	for(int i=1;i<11+d;++i,--res){
		if(res<0) break;
		if((p-w*res)%d!=0) continue;
		if(n<(p-w*res)/d+res) cout<<-1;
		else cout<<res<<" "<<(p-w*res)/d<<" "<<n-(p-w*res)/d-res;
		return;
	}
	cout<<-1;
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
