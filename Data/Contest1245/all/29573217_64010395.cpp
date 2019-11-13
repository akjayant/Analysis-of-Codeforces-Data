#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define mod 1000000007
using namespace std;

//long long jc[100001];
//long long Jc[100001];
//long long w[100001];
char a[100001];
int n,i,j,k,l;
long long ans,sum,s1,s2,S1,S2;

//long long C(int n,int m)
//{
//	return jc[n]*Jc[m]%mod*Jc[n-m]%mod;
//}

int main()
{
//	freopen("c.in","r",stdin);
	
//	w[1]=1;
//	jc[0]=1;jc[1]=1;
//	Jc[0]=1;Jc[1]=1;
//	fo(i,2,100000)
//	{
//		w[i]=mod-w[mod%i]*(mod/i)%mod;
//		
//		jc[i]=jc[i-1]*i%mod;
//		Jc[i]=Jc[i-1]*w[i]%mod;
//	}
	
	scanf("%s",a);
	n=strlen(a);
	
	fo(i,0,n-1)
	if (a[i]=='m' || a[i]=='w')
	{
		printf("0\n");
		return 0;
	}
	
	ans=1;
	fo(i,0,n-1)
	if ((a[i]=='u' || a[i]=='n') && (i==0 || a[i]==a[i-1]))
	++sum;
	else
	{
		s1=1;s2=0;
		fo(j,2,sum)
		{
			S1=(s1+s2)%mod;
			S2=s1;
			
			s1=S1;
			s2=S2;
		}
		ans=ans*(s1+s2)%mod;
		
		if (a[i]=='u' || a[i]=='n')
		sum=1;
		else
		sum=0;
	}
	s1=1;s2=0;
	fo(j,2,sum)
	{
		S1=(s1+s2)%mod;
		S2=s1;
		
		s1=S1;
		s2=S2;
	}
	ans=ans*(s1+s2)%mod;
	
	printf("%I64d\n",ans);
}