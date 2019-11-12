#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define N 100010
#define l(x) (x<<1)
#define r(x) ((x<<1)+1)
#define LL long long
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;

LL n,m,i,j,k,x,y,z,cnt,Ans,sum,T;
int a[N],b[N];
char c[N];

inline int Abs(int x){return (x<0)?-x:x;}
inline void Swap(int &a,int &b){a^=b^=a^=b;}
inline int Min(int a,int b){return (a<b)?a:b;}
inline int Max(int a,int b){return (a>b)?a:b;}

inline int read(){
	int p=0,f=1;	char	c=getchar();
	while (c<48||c>57)	{if (c=='-')	f=-1;	c=getchar();}
	while (c>=48&&c<=57)	p=(p<<1)+(p<<3)+c-48,c=getchar();
	return p*f;
}

inline LL Mi(LL x,LL y){
	LL p=x,t=1,Res=1;
	for (;t<=y;(t&y)?Res=(Res*p)%MOD:0,p=(p*p)%MOD,t<<=1);
	return Res;
}

int main(){
	#ifdef __Marvolo
	freopen("zht.in","r",stdin);
	freopen("zht.out","w",stdout);
	#endif
	scanf("%I64d%I64d",&n,&m);
	x=((Mi(2,m)-1)+MOD)%MOD;
	Ans=Mi(x,n);
	cout<<Ans<<endl;
	return 0;
}