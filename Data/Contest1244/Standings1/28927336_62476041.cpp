#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cmath>
#include<string.h>
#include<set>
#include<map>
#define LL long long
#define pr pair<int,int>
#define fr first
#define sc second
#define mp make_pair
using namespace std;
LL read( ){LL sum=0;char c=getchar( );bool f=0;while(c<'0' || c>'9') {if(c=='-') f=1;c=getchar( );}while(c>='0' && c<='9') {sum=sum*10+c-'0';c=getchar( );}if(f) return -sum;return sum;}
void read(int &sum){sum=0;char c=getchar( );bool f=0;while(c<'0' || c>'9') {if(c=='-') f=1;c=getchar( );}while(c>='0' && c<='9') {sum=sum*10+c-'0';c=getchar( );}if(f) sum=-sum;}
void read(LL &sum){sum=0;char c=getchar( );bool f=0;while(c<'0' || c>'9') {if(c=='-') f=1;c=getchar( );}while(c>='0' && c<='9') {sum=sum*10+c-'0';c=getchar( );}if(f) sum=-sum;}
inline void exgcd(LL a,LL b,LL &x,LL &y)
{
  if(!b) {x=1;y=0;return;}
  exgcd(b,a%b,x,y);
  LL t=x;x=y;y=t-a/b*y;
}
LL gcd(LL a,LL b)
{
  if(!b) return a;
  return gcd(b,a%b);
}
LL n,p,w,d,x,y;
int main( )
{
  read(n);read(p);read(w);read(d);
  LL R=gcd(w,d);
  if(p%R!=0) {puts("-1");return 0;}
  LL E=p/R;
  exgcd(w,d,x,y);
  LL T=w/R;
  y%=T;E%=T;y*=E;
  y=y%T;if(y<0) y+=T;
  x=(p-y*d)/w;
  if(x<0 || x+y>n) {puts("-1");return 0;}
  cout<<x<<' '<<y<<' '<<n-x-y;
  return 0;
}
