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
const int oo=2e5+5,inf=1e17,mod=1e9+7;
int test;
int n,k,f[oo];
char a[oo],s[oo];
queue<int> q;
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
	scanf("%s",s);
}
void xuly(){
	for(int i=0;i<n;++i) f[i]=inf;
	for(int i=0;i<n;++i){
		if(s[(n-1+i)%n]==s[i] || s[(1+i)%n]==s[i]){
			q.push(i);
			a[i]=s[i];
			f[i]=0;
		}
	}
	while(!q.empty()){
		for(int i=-1;i<2;i+=2){
			int z=q.front();
			if(1+f[z]<f[(n+i+z)%n]){
				q.push((n+i+z)%n);
				a[(n+i+z)%n]=a[z];
				f[(n+i+z)%n]=1+f[z];
			}
		}
		q.pop();
	}
	for(int i=0;i<n;++i){
		if(k<f[i]){
			if((k%2 && s[i]!='B') || (!(k%2) && s[i]!='W')) cout<<"B";
			else cout<<"W";
		}
		else cout<<a[i];
	}
}
main(){
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
