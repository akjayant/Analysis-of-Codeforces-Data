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
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>n>>s;
		ans=n;
		for(i=0;i<n;i++)
			if(s[i]=='1') ans=max({ans, 2*(i+1), 2*(n-i)});
		cout<<ans<<'\n';
	}
}