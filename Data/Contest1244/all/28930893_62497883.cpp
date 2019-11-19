#include<bits/stdc++.h>
#define ll long long
#define fr(i,x,y) for(int i=(x);i<=(y);i++)
#define rf(i,x,y) for(int i=(x);i>=(y);i--)
#define frl(i,x,y) for(int i=(x);i<(y);i++)
using namespace std;
const int N=2002;
ll x,y,d,w,n,p,g;

void read(ll &x){ scanf("%lld",&x); }

void exgcd(ll a,ll b,ll &g,ll &x,ll &y){
	if (b==0){ g=a;x=1;y=0; }
	 else{
	 	exgcd(b,a%b,g,y,x);
	 	y-=a/b*x;
	 }
}

int main(){
	read(n);read(p);read(w);read(d);
	x=p/w;if (p%w) x++;
	if (x>n) return puts("-1"),0;
	g=0,y=0;
	exgcd(d,w,g,y,x);
	if (p%g) return puts("-1"),0;
	y=y%(w/g)*(p/g%(w/g))%(w/g);
	if (y<0) y+=w/g;
	x=(p-y*d)/w;
	if (x<0||y<0) return puts("-1"),0;
	if (x+y>n) return puts("-1"),0;
	printf("%lld %lld %lld\n",x,y,n-x-y);
	return 0;
}