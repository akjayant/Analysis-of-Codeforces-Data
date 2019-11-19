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
const int N=1005;
int n;
char S[N];
int main( )
{
  int i,o,T=read( );
  while(T--)
    {
      n=read( );
      scanf("%s",S+1);
      o=10000;
      for(i=1;i<=n;i++)
	if(S[i]=='1') o=min(o,i),o=min(o,n-i+1);
      if(o==10000) printf("%d\n",n);
      else o--,printf("%d\n",2*n-o*2);
    }
  return 0;
}
