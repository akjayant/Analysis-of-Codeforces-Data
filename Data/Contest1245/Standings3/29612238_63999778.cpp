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
const int INF = 1e18;
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
		int a,b,c;
		cin>>a>>b>>c;
		string s;
		cin>>s;
		int ans=0;
		char an[n+2];
		f(i,0,n)
		an[i]='0';
		f(i,0,s.length())
		{
			if(s[i]=='R')
			{
				if(b>0)
				{
					ans++;
					b--;
					an[i]='P';
				}
			}
			else if(s[i]=='P')
			{
				if(c>0)
				{
					ans++;
					c--;
					an[i]='S';
				}
			}
			else
			{
				if(a>0)
				{
					ans++;
					a--;
					an[i]='R';
				}
			}
		}
		f(i,0,n)
		{
			if(an[i]=='0')
			{
				if(a>0)
				{
					an[i]='R';
					a--;
				}
				else if(b>0)
				{
					an[i]='P';
					b--;
				}
				else
				{
					an[i]='S';
					c--;
				}
			}
		}
		int aa=(n+1)/2;
		if(ans>=aa)
		{	
			cout<<"YES"<<endl;
			f(i,0,n)
			cout<<an[i];
			cout<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
}
