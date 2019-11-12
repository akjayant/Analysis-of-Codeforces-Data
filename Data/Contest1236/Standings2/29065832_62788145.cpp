#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, m, k, ans, mod=1e9+7;
int ret[303][303];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, temp=0;
	cin>>n;
	int r=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(r) ret[j][i]=i*n+j;
			else ret[n-1-j][i]=i*n+j;
		}
		r=1-r;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<ret[i][j]+1<<' ';
		}
		cout<<'\n';
	}
}