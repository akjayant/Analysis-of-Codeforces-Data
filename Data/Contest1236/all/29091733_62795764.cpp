#include<bits/stdc++.h>
using namespace std;
int n,cnt;
vector<int> ans[555];
bool f;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		if (!f)
		{
			for (int j=1;j<=n;j++)
			{
				cnt++;
				ans[j].push_back(cnt);
			}
		}
		else
		{
			for (int j=n;j>=1;j--)
			{
				cnt++;
				ans[j].push_back(cnt);
			}
		}
		f=!f;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<ans[i].size();j++) cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}