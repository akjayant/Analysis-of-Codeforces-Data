#include<iostream>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<cstdio>
#include<cmath>
#include<set>
#include<algorithm>
#include<vector>
#define inf 0x3f3f3f3f
#define PI acos(-1)
#define eps 1e-6
using namespace std;
typedef long long ll;

int a[10005];
int main()
{
	int cas;
	cin>>cas;
	while(cas--)
	{
		int n;
		cin>>n;
		for (int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			int cnt=0;
			for (int j=0;j<n;j++)
			{
				if (a[j]>=i) cnt++;
			}
			if (cnt>=i)
			ans=i;
		}
		cout<<ans<<endl;
	}
    return 0;
}

