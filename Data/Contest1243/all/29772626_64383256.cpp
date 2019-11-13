#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int neg=1,num=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')neg=-1;
	for(;isdigit(c);c=getchar())num=(num<<1)+(num<<3)+c-'0';
	return neg*num;
}
int T,n,cnt,a[10];
string s1,s2;
int main()
{
	T=read();
	while(T--)
	{
		n=read();cnt=0;
		cin>>s1>>s2;
		if(s1==s2)
		{
			printf("YES\n");
			continue;
		}
		for(int i=1;i<=n && cnt<=2;i++)if(s1[i-1]!=s2[i-1])a[++cnt]=i;
		if(cnt!=2)
		{
			printf("NO\n");
			continue;
		}
		swap(s1[a[1]-1],s2[a[2]-1]);
		if(s1==s2)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

