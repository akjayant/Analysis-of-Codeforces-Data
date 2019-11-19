#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long 
const int maxn = 2e5+10;
const int INF = 1e9+7;
int n,k;
char c[maxn];
int l[maxn],r[maxn];
int a[maxn];
char s[maxn],s2[maxn];
int flag[maxn];
int f;
void init1()
{
	if(!flag[1])
	for(int i=n;i;i--)
	{
		if(flag[i])
		{
			l[1]=n-i+1;
			s[1]=c[i];
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(flag[i])
		{
			l[i]=0;
			s[i]=c[i];
		}
		else if(i>=2)
		{
			l[i]=l[i-1]+1;
			s[i]=s[i-1];
		}
	}
}
void init2()
{
	if(!flag[n])
	for(int i=1;i<=n;i++)
	{
		if(flag[i])
		{
			r[n]=i;
			s2[n]=c[i];
			break;
		}
	}
	for(int i=n;i;i--)
	{
		if(flag[i])
		{
			r[i]=0;
			s2[i]=c[i];
		}
		else if(i<n)
		{
			r[i]=r[i+1]+1;
			s2[i]=s2[i+1];
		}
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",c+1);
	for(int i=1;i<n;i++) if(c[i]==c[i+1]) flag[i]=flag[i+1]=1;
	if(c[1]==c[n]) flag[1]=flag[n]=1;
	char tmp;
	init1();
	init2();
	for(int i=1;i<=n;i++) if(flag[i]) f=1;
	if(!f)
	{
		if(k%2==1)
		{
			for(int i=1;i<=n;i++)
			if(c[i]=='B') printf("W");
			else printf("B");
		}
		else
		{
			for(int i=1;i<=n;i++)
			if(c[i]=='W') printf("W");
			else printf("B");
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(l[i]<=r[i])
		{
			if(l[i]<=k)
			printf("%c",s[i]);
			else if(k%2==1&&c[i]=='W') printf("B");
			else if(k%2==1&&c[i]=='B') printf("W");
			else if(k%2==0&&c[i]=='W') printf("W");
			else if(k%2==0&&c[i]=='B') printf("B");
		}
		else
		{
		   	if(r[i]<=k)
			printf("%c",s2[i]);
			else if(k%2==1&&c[i]=='W') printf("B");
			else if(k%2==1&&c[i]=='B') printf("W");
			else if(k%2==0&&c[i]=='W') printf("W");
			else if(k%2==0&&c[i]=='B') printf("B");	
		}
	}
	return 0;
}
/*
16 3
BWBWBBWBWBWBBWBW
*/