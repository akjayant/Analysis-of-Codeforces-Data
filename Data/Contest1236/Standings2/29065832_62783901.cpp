#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, m, k, ans, mod=1e9+7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, temp=0;
	cin>>n;
	while(n--)
	{
		int x, y, z;
		cin>>x>>y>>z;
		ans=0;
		ans+=min(z/2, y);
		y-=ans;
		ans+=min(x, y/2);
		cout<<3*ans<<'\n';
	}
}