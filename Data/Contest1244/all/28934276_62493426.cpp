#include<bits/stdc++.h>

#define N 2000005
#define rd(x) x=read()
#define int long long

using namespace std;

int n,m,k;
int s[N],t[N];

inline void print(int x,int f)
{
	if(f)swap(s[x+m],s[x]);
	printf("%lld\n",k);
	for(int i=1;i<=n;i++)printf("%lld ",s[i]);
	cout<<endl;
	for(int i=1;i<=n;i++)printf("%lld ",t[i]);
	cout<<endl;
	exit(0);
}

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}


signed main() 
{
	rd(n),rd(m),k=m;int ok=0;
	for(int i=1;i<=n;i++)s[i]=t[i]=i;
	for(int i=1;i<=10;i++)sort(s+1,s+n+1),sort(t+1,t+n+1);
	for(int i=1;i<=n;i++)swap(s[i],s[n-i+1]);
	for(int i=1;i<=n;i++)swap(t[i],t[n-i+1]);
	int mid=(n>>1),lmid=(n>>1),rmid=(n>>1);
	if(n*(n+1)/2>m){puts("-1");return 0;}
	m-=n*(n+1)/2;
	if(lmid==mid&&rmid==mid)
		for(int i=1;i<=mid;i++)
		{
			int t=1-2*i+n,fl=0,flg=1;
			if(t<m)m-=t,swap(s[n-i+1],s[i]);
			else print(i,1),ok=1;
		}
	if(ok);else{k-=m;for(int i=1;i<=n;i++)s[i]=i,t[i]=n-i+1;print(1000,0);}


	return 0;
}
