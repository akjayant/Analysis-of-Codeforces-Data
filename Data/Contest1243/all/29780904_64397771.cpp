//   HVARDHANSINGH   //  

#include <bits/stdc++.h>
using namespace std;

#define F               first
#define S               second
#define int             long long 
#define sz(a)           (int)((a).size())
#define pb              push_back
#define ppb             pop_back
#define all(c)          (c).begin(), (c).end()
#define SORT(v)         sort(all(v))
#define RSORT(v)		sort((v).rbegin(), (v).rend())
#define rep(i, a, b)    for(int i = a; i < b; i++)
#define gcd(a,b)        __gcd(a,b)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define sqr(a)          ((a) * (a))
#define inf             (int)2e18
#define pow(i,n)        (int)pow((int)i,n)
#define endl            "\n"
#define mod             1000000007
#define M               100005

typedef vector<int>                   vi;
typedef vector<vector<int> >          vvi;
typedef map<int,int>                  MAP;

void solve()
{
	int n;	cin>>n;
	string s,t;	cin>>s>>t;
	vector< pair<int,int> > ans;
	map<char, int> mp;
	rep(i,0,n)
	{
		mp[s[i]]++;
		mp[t[i]]++;
	}
	for(auto x:mp)
	{
		if(x.S & 1)	
		{
			cout<<"NO"<<endl;
			return;
		}
	}
	
	rep(i,0,n)
	{
		// we'll change t 
		
		// try to make it equal to s
		
		if(s[i]==t[i])	continue;
		
		rep(j,i+1,n)
		{
			if(s[j]==s[i])
			{
				ans.pb({j+1,i+1});
				swap(s[j], t[i]);
				break;
			}
		}
		if(s[i]!=t[i])
		{
			rep(j,i+1,n)
			{
				if(t[j]==s[i])
				{
					ans.pb({i+1,i+1});
					ans.pb({i+1,j+1});
					swap(s[i], t[i]);
					swap(s[i], t[j]);
					break;
				}
			}
		}
		
	}
	if(s==t)
	{
		cout<<"YES"<<endl;
		cout<<sz(ans)<<endl;
		for(auto x:ans)
		{
			cout<<x.F<<" "<<x.S<<endl;
		}
	}
	else	cout<<"NO";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int T = 1;
    cin>>T;
	
    while(T--)
    {
    	solve();
    }
    return 0;
}