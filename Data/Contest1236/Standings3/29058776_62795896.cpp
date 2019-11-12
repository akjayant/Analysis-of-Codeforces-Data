#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
	return x*f;
}
const int N=507;
int n,A[N][N],L[N],R[N];
int main()
{
	n=read(); int tot=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) A[i][j]=++tot;
		L[i]=1,R[i]=n;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if((i^j)&1) printf("%d ",A[j][L[j]++]);
			else printf("%d ",A[j][R[j]--]);
		}
		puts("");
	}
	return 0;
}