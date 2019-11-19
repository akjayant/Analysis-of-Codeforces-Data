#include<bits/stdc++.h>
using namespace std;
#define N 200003
#define LL long long
#define mod 998244353

int n,tot;
int a[N];
LL ans1,ans2;

inline int read(){
	int X=0,w=0;
	char ch=0;
	while (ch<'0' || ch>'9')
	  w|=ch=='-',ch=getchar();
	while (ch>='0' && ch<='9')
	  X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
	return w ? -X : X;
}

inline bool cmp(int x,int y){
	return x>y;
}

int main(){
	n=read();
	for (int i=1;i<=n;i++)
	  a[i]=read();
	tot=(n+1)/2;
	sort(a+1,a+1+n,cmp);
	ans1=0;
	for (int i=1;i<=tot;i++)
	  ans1+=a[i];
	ans2=0;
	for (int i=tot+1;i<=n;i++)
	  ans2+=a[i];
	ans1=ans1*ans1+ans2*ans2;
	printf("%lld\n",ans1);
	return 0;
}