#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define M 1000000007
using namespace std;
const int inf=4e18;
vector<int> prime_factors(int n)
{
	vector<int> f;
	for(int x=2;x*x<=n;x++)
	{
		if(n%x==0)
			f.pb(x);
		while(n%x==0)
			n/=x;
	}
	if(n>1)
		f.push_back(n);
	return f;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n;cin>>n;
	vector<int> v=prime_factors(n);
	if(v.size()==1)
		cout<<v[0]<<endl;
	else
		cout<<1<<endl;
}
