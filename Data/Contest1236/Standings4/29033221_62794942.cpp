#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector < vector <int> > v(n);
	int curr = 1;
	for(int i = 0;i < n;i++)
	{
		if(i&1)
		{
			for(int j = 0;j<n;j++)
			{
				v[j].push_back(curr);
				curr++;
			}
		}
		else
		{
			for(int j = n-1;j>=0;j--)
			{
				v[j].push_back(curr);
				curr++;
			}
		}
	}
	for(auto e: v)
	{
		for(auto f: e)
		{
			cout << f << " ";
		}
		cout << endl;
	}
}