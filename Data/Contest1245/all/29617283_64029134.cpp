#include<bits/stdc++.h>
#define ll long long
#define N 1000050
#define pi acos(-1)
#define mod 1000000007
#define endl '\n'
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,-1,sizeof(x))
using namespace std;

ll t,n,k,l,r,a[20][20],m[200],b,c,ans,sum;
double dp[N][2];
char s[N];

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=0;i<10;i++)
	if(i%2)
	for(int j=9;j>=0;j--)
	a[i][j]=++sum;
	else
	for(int j=0;j<10;j++)
	a[i][j]=++sum;
	for(int i=9;i>=0;i--)
	for(int j=0;j<10;j++)
	{
		cin>>k;
		if(k)
		m[a[i][j]]=a[i+k][j];
	}
	dp[0][0]=dp[0][1]=100;
	for(int i=99;i>=95;i--)
	{
		int t=i-94;
		dp[i][0]=t;
		for(int j=i+1;j<=100;j++)
		dp[i][0]+=dp[j][0]+1;
		dp[i][0]/=6-t;
		dp[i][1]=100;
	}
	for(int i=94;i>0;i--)
	{
		for(int j=1;j<=6;j++)
		dp[i][0]+=min(dp[i+j][0],dp[i+j][1]);
		dp[i][0]/=6;
		dp[i][0]+=1;
		if(m)
		dp[i][1]=dp[m[i]][0];
		else
		dp[i][1]=100;
	}
	printf("%.7lf",min(dp[1][0],dp[1][1]));
	return 0;
}
