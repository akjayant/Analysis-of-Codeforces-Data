#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ld long double
#define f(i,x,n) for(int i=x;i<n;i++)
#define int long long
#define mod 1000000007
#define endl "\n"
#define MAXN 300001 
const int INF = 1e12;
void fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
int32_t main() 
{
	fastio();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int ans=0;
		f(i,0,n)
		{
			if(s[i]=='1')
			{
				ans+=2;
			}
			else
				ans++;
		}
		f(i,0,n)
		{
			if(s[i]=='1')
			{
				int t1=(i+1)*2,t2=(n-i)*2;
				ans=max(ans,t1);
				ans=max(ans,t2);
			}
		}
		cout<<ans<<endl;
	}	
}