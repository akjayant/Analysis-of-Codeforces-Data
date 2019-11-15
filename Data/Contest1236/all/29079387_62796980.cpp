#include<stdio.h>
#include<math.h>
#include<string.h>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#define pb push_back
#define all(x) x.begin(),x.end()
#define INF 0x3f3f3f3f
#define dd(x) cout<<#x<<" = "<<x<<","
#define de(x) cout<<#x<<" = "<<x<<"\n"
using namespace std;
typedef long long ll;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=i,k=n-i+1,t=0;j<=n*n||k<=n*n;j+=n,k+=n,t++)
		{
			if(t%2==0)
			{
				printf("%d ",j);
			}
			else
			{
				printf("%d ",k);
			}
		} 
		printf("\n");
	}
}
