#include <bits/stdc++.h>
using namespace std;

const int n=10;
int t,rx[n*n*+10],ry[n*n+10],g[n+10][n+10],a[n+10][n+10];
double f[n*n+10],h[n*n+10];

double made(int k)
{
	int i;double now=6.0;
	for (i=1;k-i>0 && i<=6;i++) now+=f[k-i];
	now/=double(i-1);
	return now;
}

int upd(int k,int num) {return (g[rx[k]-num][ry[k]]);}

int main()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
		if (i%2==0) for (int j=n;j>=1;j--) {rx[++t]=i;ry[t]=j;g[i][j]=t;}
		if (i%2==1) for (int j=1;j<=n;j++) {rx[++t]=i;ry[t]=j;g[i][j]=t;}
	}
	
	f[1]=0.0;h[1]=0.0;
	for (int i=2;i<=n*n;i++)
	{
		double now=made(i);
		h[i]=now;
		if (a[rx[i]][ry[i]]>0) now=min(now,h[upd(i,a[rx[i]][ry[i]])]);
		f[i]=now;
	}
	printf("%.10lf\n",f[n*n]);
	
	return 0;
}
