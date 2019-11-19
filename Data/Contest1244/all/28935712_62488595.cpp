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
int n,m,k,minn=inf,maxx;
multiset<int> s;
multiset<int>::iterator id;
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
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		s.insert(x);
		maxx=max(x,maxx);
		minn=min(x,minn);
	}
}
void xuly(){
	n=0;
	while(maxx!=minn){
		int x=s.count(minn),y=s.count(maxx),z;
		if(min(x+m,y+n)>k) break;
		if(x+m<=y+n){
			id=s.upper_bound(minn);
			z=min(k/(x+m),(*id)-minn);
			minn+=z;
			m+=x;
			k-=m*z;
		}
		else{
			id=s.lower_bound(maxx);
			--id;
			z=min(k/(y+n),maxx-(*id));
			maxx-=z;
			n+=y;
			k-=n*z;
		}
	}
	cout<<maxx-minn;
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
