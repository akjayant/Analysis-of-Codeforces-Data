#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> res[301];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i=0;i<=(n-1);i++)
	{
		if (i%2 == 0)
		{
			for (int j=1;j<=n;j++)
				res[j].push_back(n*i+j);
		}
		else
		{
			for (int j=1;j<=n;j++)
				res[n-j+1].push_back(n*i+j);
		}		
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<res[i].size();j++)
			cout << res[i][j] << ' ';
		cout << '\n';
	}	
}