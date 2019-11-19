#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
const int MN=555;
int a[MN*2],s[MN*2],st=1,cnt=0,ans,di=1,dj=1;
struct No{
	int pos,zh;
}q[2020];

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char x;
		cin>>x;
		if(x=='(')
			a[i]=1;
		else
			a[i]=-1;
		a[i+n]=a[i];
	}
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	if(s[n]!=0)
		goto zlxx;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
			if(a[i]!=a[j]||i==j)
			{
				cnt=0,st=1;
				int nans=0;
				swap(a[i],a[j]);
				swap(a[i+n],a[j+n]);
				for(int k=1;k<=2*n;k++)
					s[k]=s[k-1]+a[k];
				for(int k=1;k<n;k++)
				{
					while(st<=cnt&&q[cnt].zh>=s[k])
						cnt--;
					q[++cnt].pos=k,q[cnt].zh=s[k];
				}
				for(int k=n;k<2*n;k++)
				{
					while(st<=cnt&&q[cnt].zh>=s[k])
						cnt--;
					while(st<=cnt&&k-q[st].pos>=n)
						st++;
					q[++cnt].pos=k,q[cnt].zh=s[k];
					if(q[st].zh-s[k-n]>=0)
						nans++;
				}
				
				if(nans>ans)
					ans=nans,di=i,dj=j;
				swap(a[i],a[j]);
				swap(a[i+n],a[j+n]);
			}
	}
//	if(ans==0)
	zlxx:;
	cout<<ans<<endl<<di<<' '<<dj<<endl;
}