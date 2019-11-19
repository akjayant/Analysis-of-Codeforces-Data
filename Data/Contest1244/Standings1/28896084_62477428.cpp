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

bool v[100009];
ll n,p,w,d,z;
void solve(){
	cin>>n>>p>>w>>d;
	
	while(1){
		if(p-d*z<0)break;
		ll gl=(p-d*z)%w;
		
		if(gl==0){
			if(z+(p-d*z)/w<=n)
			{cout<<(p-d*z)/w<<" "<<z<<" "<<n-z-(p-d*z)/w;exit(0);}
			break;
		}
		
		if(v[gl])break;
		v[gl]=1;
		z++;
	}
	
	cout<<-1;
}

