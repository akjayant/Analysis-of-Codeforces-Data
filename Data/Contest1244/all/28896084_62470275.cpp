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
bool test=true;int main(){int tst=1;if(test)cin>>tst;while(tst--)solve();}

void solve(){
	int n;
	string s;
	cin>>n>>s;
	int lf=-1,rg=-1;
	for(int i=0;i<n;i++)
	if(s[i]=='1')
	{lf=i;break;}
	for(int i=n-1;i>=0;i--)
	if(s[i]=='1')
	{rg=i;break;}
	
//	cout<<lf<<" as "<<rg<<endl;
	
	if(lf==-1)cout<<n<<endl;
	else cout<<max((n-lf)*2,rg*2+2)<<endl;
}

