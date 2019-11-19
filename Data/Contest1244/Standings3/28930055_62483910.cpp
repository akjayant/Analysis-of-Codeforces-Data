#include<bits/stdc++.h>
#define fi first
#define se second 
#define mk make_pair
#define pb push_back
#define P pair<ll,ll>
#define INF 0x3f3f3f3f
#define mod 1000000007
#define lowbit(n) n&-n
#define mem(i) memset(i,0,sizeof(i))
#define bcnt(x) __builtin_popcount(x)
#define bcntz(x) __builtin_ctz(x)
using namespace std;
const int maxn=100010;
typedef long long ll;
typedef long double ld; 
ll n,m,p,w,d;
int gi(){
    char a=getchar();int b=0;
    while(a<'0'||a>'9')a=getchar();
    while(a>='0'&&a<='9')b=b*10+a-'0',a=getchar();
    return b;
}
ll mabs(ll x){
	return x<0 ? -x:x; 
}
void exgcd(ll a,ll b,ll& d,ll& x,ll& y){
    if(!b){d=a;x=1;y=0;}
    else {exgcd(b,a%b,d,y,x);y-=x*(a/b);}
}
bool solve(ll a,ll b,ll c,ll &x)
{
	ll d,y;
	exgcd(a,c,d,x,y);
	if(b%d)
		return 0;
	ll t=b/d;
	x=x*t;
	ll _b=mabs(c/d);
	x=(x%_b+_b)%_b;
	return 1;
}


void no(){
	cout<<"-1"<<endl;
	exit(0);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>p>>w>>d;
	//xw+yd=p
	ll x,y,gcdd;
	ll yu1=p%w;
	ll yu2=d%w;
	int ans=solve(yu2,yu1,w,y);
	if(!ans){
		no();
	}
	else{
		if(y*d>p) no();
		x=(p-y*d)/w;
		
		if(x+y>n){
			no();
		}
		cout<<x<<" "<<y<<" "<<n-x-y<<endl;
	}
	
}

