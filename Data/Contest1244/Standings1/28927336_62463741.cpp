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
const int mod=1000000007;
const int N=505;
int main( )
{
  int T=read( );
  int i,j,a,b,c,d,k;
  while(T--)
    {
      read(a);read(b);read(c);read(d);read(k);
      for(i=0;i<=k;i++)
	{
	  j=k-i;
	  if(c*i>=a && d*j>=b) {printf("%d %d\n",i,j);goto ov;}
	}
      puts("-1");
    ov:;
    }
  return 0;
}
      
