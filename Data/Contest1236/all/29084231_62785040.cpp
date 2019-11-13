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
using namespace std;

int n,m,i,j,k,x,y,z,cnt,Ans,sum,T;
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

int main(){
	#ifdef __Marvolo
	freopen("zht.in","r",stdin);
	freopen("zht.out","w",stdout);
	#endif
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&x,&y,&z);
		Ans=0;	sum=0;
		for (i=0;i<=100;i++)
			for (j=0;j<=100;j++){
				if (x>=i&&y>=2*i+j&&z>=2*j){
					sum=3*i+3*j;
					Ans=Max(Ans,sum);
				}
			}
		printf("%d\n",Ans);
	}
	return 0;
}