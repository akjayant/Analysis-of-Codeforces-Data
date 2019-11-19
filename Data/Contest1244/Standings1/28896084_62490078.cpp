# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> PII;
# define nl cout<<endl
# define fr first
# define sc second
# define mk make_pair
# define pb push_back
# define all(a) (a).begin(),(a).end()
# define N 300009
# define INF 998244353
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define test4(x,y,z,a) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<"		a is "<<a<<endl
# define test3(x,y,z) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<endl
# define test2(x,y) cout<<"x is "<<x<<"		y is "<<y<<endl
# define test1(x) cout<<"x is "<<x<<endl
void solve();
bool test=false;int main(){int tst=1;if(test)cin>>tst;while(tst--)solve();}

ll n,k,lf,rg,lff,rgg;
ll a[100009];

void solve(){
	cin>>n>>k;
	
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	
	lf=1,rg=n;
//	for(int i=1;i<=n;i++)
//	cout<<a[i]<<" ";
//	cout<<endl;
	
	while(lf<=rg){
		//move lf
		if(!lff)
		while(lf<=rg){
			lf++;
			if(a[lf]!=a[lf-1])break;
		}
		//move rg
		if(!rgg)
		while(lf<=rg){
			rg--;
			if(a[rg]!=a[rg+1])break;
		}
//		cout<<lf<<" "<<rg;
		
		if(lf-1<n-rg){
			if((a[lf]-a[lf-1])*(lf-1)>k)
				{cout<<a[rg+1]-a[lf-1]-(k/(lf-1));exit(0);}
			k=k-(a[lf]-a[lf-1])*(lf-1);
//			cout<<"lf "<<k<<endl;getchar();
			rgg=1;lff=0;
		}
		else
		{
			if((a[rg+1]-a[rg])*(n-rg)>k)
				{cout<<a[rg+1]-a[lf-1]-(k/(n-rg));exit(0);}
			k=k-(a[rg+1]-a[rg])*(n-rg);
//			cout<<"rg "<<k<<endl;getchar();
			lff=1;rgg=0;
		}
	}
	cout<<0;
}

