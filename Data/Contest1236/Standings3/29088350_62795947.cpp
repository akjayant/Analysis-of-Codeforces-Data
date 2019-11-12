#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
int a[330][330];
int main()
{
	int n;
	cin>>n;
	int j=1;
	for(int k=0;k<n;k++)
	{
		if(k&1)
		{
			for(int i=0;i<n;i++)
				a[i][k]=j++;
		}
		else
		{
			for(int i=n-1;i>=0;i--)
				a[i][k]=j++;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int k=0;k<n;k++)
			cout<<a[i][k]<<" ";
		cout<<endl;
	}
}