#include<bits/stdc++.h>
using namespace std;
string s,t;
char op(char c)
{
	if(c=='W') return 'B';
	else return 'W';
}
int main()
{
	int n,k;
	cin>>n>>k;
	cin>>s;
	t=s;
	s=' '+s+s+' ';
	int fr=1;
	bool flag=(s[1]==s[n]);
	for(int i=2;i<=2*n+1;i++)
	{
		if(s[i]==s[i-1])
		{
			if(!flag)
			{
				int l=fr,r=i-2;
				for(int j=1;l<=r and j<=k;l++,r--,j++)
					s[l]=s[fr-1],s[r]=s[i-1];
				if((k&1) and l<=r)
					for(int j=l;j<=r;j++)  s[j]=op(s[j]);
				flag=true;
			 } 
		}
		else if(flag)
		{
			fr=i;
			flag=false;
		}
	}
	int pos;
	if(t[0]==t[n-1])  pos=1;
	else
	{
		for(pos=1;t[pos]!=t[pos-1] and pos<n;pos++)  ;
		if(pos==n) 	pos=1;
	}
	for(int i=n+1;i<=pos+n-1;i++)  putchar(s[i]);
	for(int i=pos;i<=n;i++)  putchar(s[i]);
	return 0;
}