#include<stdio.h>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int f[250000];
int n,m;

int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin>>n>>m;
    f[1]=2;f[2]=4;
    for(int i=3;i<=n+m;i++)
    {
    	f[i]=(f[i-1]+f[i-2])%1000000007;
	}
	cout<<(f[n]+f[m]-2)%1000000007;
	return 0;
}
