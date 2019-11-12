//   HVARDHANSINGH   //  

#include <bits/stdc++.h>
using namespace std;

#define F               first
#define S               second
#define int             long long 
#define sz(a)           int((a).size())
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
	int n ;	cin>>n;
	string s,t;	cin>>s>>t;
	
	if(s==t)
	{
		cout<<"YES"<<endl;
		return ;
	}
	
	int x,y;
	int c=0;
	rep(i,0,n)
	{
		if(s[i]!=t[i])
		{
			c++;
			if(c==1)	
			{
				x=i;
			}
			else if(c==2)	y=i;
			else
			{
				cout<<"NO"<<endl;
				return;
			}
		}
	}
	
	if(c==2)
	{
		if(s[x]==s[y] && t[x]==t[y])
		{
			cout<<"YES"<<endl;
		}
		else	cout<<"NO"<<endl;
	}
	else	
		cout<<"NO"<<endl;
	
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