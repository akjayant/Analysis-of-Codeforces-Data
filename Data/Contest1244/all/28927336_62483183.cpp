#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cmath>
#include<string.h>
#include<set>
#include<map>
#include<stdlib.h>
#define LL long long
#define pr pair<int,int>
#define fr first
#define sc second
#define mp make_pair
using namespace std;
LL read( ){LL sum=0;char c=getchar( );bool f=0;while(c<'0' || c>'9') {if(c=='-') f=1;c=getchar( );}while(c>='0' && c<='9') {sum=sum*10+c-'0';c=getchar( );}if(f) return -sum;return sum;}
void read(int &sum){sum=0;char c=getchar( );bool f=0;while(c<'0' || c>'9') {if(c=='-') f=1;c=getchar( );}while(c>='0' && c<='9') {sum=sum*10+c-'0';c=getchar( );}if(f) sum=-sum;}
void read(LL &sum){sum=0;char c=getchar( );bool f=0;while(c<'0' || c>'9') {if(c=='-') f=1;c=getchar( );}while(c>='0' && c<='9') {sum=sum*10+c-'0';c=getchar( );}if(f) sum=-sum;}
const int N=100005;
LL n,k,a[N];
int main( )
{
  LL i,j;
  read(n);read(k);
  for(i=1;i<=n;i++) read(a[i]);
  sort(a+1,a+n+1);
  LL ans=a[n]-a[1];
  i=1;j=n;
  bool S=0;
  while(i!=j)
    {
      if(!S)
	{
	  LL P=n-j+1;
	  LL D=a[j]-a[j-1];
	  if(k>P*D) k-=P*D,ans-=D,j--,S^=1;
	  else {ans-=k/P;break;}
	}
      else
	{
	  LL P=i;
	  LL D=a[i+1]-a[i];
	  if(k>P*D) k-=P*D,ans-=D,i++,S^=1;
	  else {ans-=k/P;break;}
	}
    }
  cout<<ans;
  return 0;
}
