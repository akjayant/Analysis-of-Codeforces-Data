#include <bits/stdc++.h>
using namespace std;

#define int long long int


#undef int
int main()
{
#define int long long int
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;
	int a[400][400], c = 1;
	for(int j = 0;j<n;j++)
	{
		int st = j*n+1, en = j*n+n;
		if(j&1)
		{
			for(int i = n-1;i>=0;i--)
				a[i][j] = c++;
		}
		else
		{
			for(int i = 0;i<n;i++)
				a[i][j] = c++;
		}
	}
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}