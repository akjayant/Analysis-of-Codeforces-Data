#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long a[N],P=1e9+7;
int main()
{
	a[1]=1,a[2]=2,a[3]=3;
	for(register int i=4;i<=100000;i++) a[i]=(a[i-1]+a[i-2])%P; 
	string k; cin>>k;
	long long ans=1;
	for(register int i=0;i<k.size();i++)
	{
		if(k[i]=='m'||k[i]=='w') 
		{
			cout<<0; return 0;
		}
		if(k[i]=='u')
		{
			int j=i; int fl=0;
			while(k[j]=='u'&&j<k.size()) fl++,j++;
			i=j-1; ans=ans*a[fl]%P;
		}
	}
	for(register int i=0;i<k.size();i++)
	{
		if(k[i]=='n')
		{
			int j=i; int fl=0;
			while(k[j]=='n'&&j<k.size()) fl++,j++;
			i=j-1; ans=ans*a[fl]%P;
		}
	}
	cout<<ans;
}