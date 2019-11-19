#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>
#include <ctime>

using namespace std;

long long t, n, m, cnt1[2], cnt2[2], ans;

int main()
{
	ios::sync_with_stdio(false);
	int u;
	cin>>t;
	while(t--)
	{
		cnt1[0]=cnt1[1]=cnt2[0]=cnt2[1]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>u;
			if(u&1)
				cnt1[0]++;
			else
				cnt2[0]++;
		}
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>u;
			if(u&1)
				cnt1[1]++;
			else
				cnt2[1]++;
		}
		ans=cnt1[0]*cnt1[1]+cnt2[0]*cnt2[1];
		cout << ans << "\n";
	}
	return 0;
}