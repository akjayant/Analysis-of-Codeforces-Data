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
const int N=1007;
int T,n;
char A[N];
int main()
{
	T=read();
	while(T--)
	{
		n=read(); scanf("%s",A+1);
		int L=n+1,R=0;
		for(int i=1;i<=n;i++)
			if(A[i]=='1') L=min(L,i),R=max(R,i);
		if(!R) printf("%d\n",n);
		else printf("%d\n",max(R*2,(n-L+1)*2));
	}
	return 0;
}