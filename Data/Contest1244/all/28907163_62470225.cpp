#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
#define ll long long 
int t,n;
const int maxn = 1010;
char c[maxn];
int ans;
int main()
{
	int t;
	scanf("%d",&t);
    while(t--)
    {
    	scanf("%d",&n);
    	scanf("%s",c+1);
    	ans=n;
    	for(int i=1;i<=n;i++)
    	{
    		if(c[i]=='0') continue;
    		ans=max(2*i,ans);
    		ans=max(2*(n-i+1),ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}