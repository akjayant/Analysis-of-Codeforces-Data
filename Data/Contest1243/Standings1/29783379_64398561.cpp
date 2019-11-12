#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;	

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define test() ll t;cin>>t;for(ll test = 1;test<=t;test++)
#define f first
#define s second
#define pb push_back
#define nl cout<<"\n"
#define MOD(x) ((x%P)+P)%P
#define vec(v) loop(i,0,v.size()) cout<<v[i]<<" "; nl
const int N = 100005;
const ll P = 1000000007;
const double eps = 1e-6;

bool poss(string s)
{
	sort(s.begin(), s.end());
	for(int i=0; i<s.size(); i+=2)
	{
		if(s[i]!=s[i+1])
			return 0;
	}
	return 1;
}

int main()
{
	fastio();
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	test()
	{
		int n; cin>>n;
		string s,t;
		cin>>s>>t;

		if(!poss(s+t))
		{
			cout<<"No",nl;
			continue;
		}

		cout<<"Yes",nl;
		vector<int> ans;

		for(int i=0; i<n; i++)
		{
			if(s[i]==t[i])
				continue;
			for(int j=i+1; j<n; j++)
			{
				if(s[j]==s[i])
				{
					ans.pb(j+1); ans.pb(i+1);
					swap(s[j], t[i]);
					break;
				}
				if(t[j]==s[i])
				{
					ans.pb(i+1); ans.pb(i+1);
					ans.pb(i+1); ans.pb(j+1);
					swap(t[i], t[j]);
					break;
				}
			}
		}
		cout<<ans.size()/2,nl;
		for(int i=0;i<ans.size(); i++)
		{
			cout<<ans[i]<<" ";
			if(i%2)
				nl;
		}

	}


	cerr << "\nTime elapsed : " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
	return 0;
}