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
# define N 100009
# define INF 998244353
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define test4(x,y,z,a) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<"		a is "<<a<<endl
# define test3(x,y,z) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<endl
# define test2(x,y) cout<<"x is "<<x<<"		y is "<<y<<endl
# define test1(x) cout<<"x is "<<x<<endl
void solve();
bool test=false;int main(){int tst=1;if(test)cin>>tst;while(tst--)solve();}
ll k[]={1,2,3},qq;
ll n,p,q,zz,mn=INF,kk;
ll a[5][N];
ll an[27][N];
vector <ll> adj[N];

void btr(ll x, ll y, ll z, ll pr){
//	cout<<"  \n "<<x<<" "<<pr<<endl;
//	getchar();
	an[z][x]=k[y];
	y=(y+1)%3;
	if(adj[x][0]!=pr)
	btr(adj[x][0],y,z,x);
	else if(adj[x].size()>1) btr(adj[x][1],y,z,x);
}

void solve(){
	cin>>n;
	
	for(int i=1;i<=n;i++)cin>>a[1][i];
	for(int i=1;i<=n;i++)cin>>a[2][i];
	for(int i=1;i<=n;i++)cin>>a[3][i];
	
	for(int i=0;i<n-1;i++){
		cin>>p>>q;
		adj[p].pb(q);
		adj[q].pb(p);
		if(adj[p].size()>2 || adj[q].size()>2){cout<<"-1";exit(0);}
	}
	
	for(int i=1;i<=n;i++)if(adj[i].size()==1)qq=i;
	
	do{
		btr(qq,0,zz,0);
		zz++;
	}while(next_permutation(k,k+3));
	
	for(int i=0;i<zz;i++){
		ll sm=0;
		for(int j=1;j<=n;j++)
			sm=sm+a[an[i][j]][j];
		if(i==0 || sm<mn)mn=sm,kk=i;
	}
	
	cout<<mn<<endl;
	
	for(int i=1;i<=n;i++)
	cout<<an[kk][i]<<" ";
}

