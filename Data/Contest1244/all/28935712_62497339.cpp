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
const int oo=1e6+5,inf=1e17,mod=1e9+7;
int test;
int n,k,res,tong,hieu,ans[oo];
queue<int> q;
stack<int> st;
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
}
void xuly(){
	for(int i=1;i<=n;++i){
		st.push(i);
		q.push(i);
		k-=i;
		res+=i;
	}
	if(0>k){
		cout<<-1;
		return;
	}
	while(!st.empty() && !q.empty()){
		int vt1=st.top(),vt2=q.front();
		if(vt2>vt1) break;
		if(k<vt1-vt2){
			st.pop();
			ans[vt1]=vt1;
		}
		else{
			ans[vt1]=vt2;
			ans[vt2]=vt1;
			k-=vt1-vt2;
			res+=vt1-vt2;
			st.pop();
			q.pop();
		}
	}
	cout<<res<<xd;
	for(int i=1;i<=n;++i) cout<<ans[i]<<" ";
	cout<<xd;
	for(int i=1;i<=n;++i) cout<<i<<" ";
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
