#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

char s[N],c[N];
int mx[N],a[N];

int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	s[0]=s[n];s[n+1]=s[1];
	for(i=1;i<=n;i++)
		if(s[i]==s[i-1])a[i]=1;
	for(i=1;i<=n;i++)
		if(s[i]==s[i+1])a[i]=1;
	for(i=0;i<=n+1;i++)
		mx[i]=1e9+7;
	for(i=1;i<=n;i++)
		if(a[i]==1)mx[i]=0,c[i]=s[i];
	for(i=1;i<=n;i++)
		if(mx[i-1]+1<mx[i])mx[i]=mx[i-1]+1,c[i]=c[i-1];
	mx[0]=mx[n],c[0]=c[n];
	for(i=1;i<=n;i++)
		if(mx[i-1]+1<mx[i])mx[i]=mx[i-1]+1,c[i]=c[i-1];
	//for(i=1;i<=n;i++)cout<<c[i]<<mx[i]<<endl;
	for(i=n;i;i--)
		if(mx[i+1]+1<mx[i])mx[i]=mx[i+1]+1,c[i]=c[i+1];
	mx[n+1]=mx[1],c[n+1]=c[1];
	for(i=n;i;i--)
		if(mx[i+1]+1<mx[i])mx[i]=mx[i+1]+1,c[i]=c[i+1];
	for(i=1;i<=n;i++)
		if(mx[i]<=m)printf("%c",c[i]);
		else printf("%c",m&1?'W'+'B'-s[i]:s[i]);
	return 0;
}