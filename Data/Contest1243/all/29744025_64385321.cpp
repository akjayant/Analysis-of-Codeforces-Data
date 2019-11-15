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
	int k;
	cin>>k;
	while(k--)
	{
		int n;
		cin>>n;
		string s,t;
		cin>>s>>t;
		int an=0;
		int aa[26];
		memset(aa,0,sizeof(aa));
		vector<pair<char,char>>vc;
		f(i,0,n)
		{
			aa[s[i]-'a']++;
			aa[t[i]-'a']++;
			if(s[i]!=t[i])
			{
				an++;
				vc.pb(mp(s[i],t[i]));
			}
		}
		int fg=0;
		f(i,0,26)
		{
			if(aa[i]%2!=0)
				fg=1;
		}
		if(vc.size()==2)
		{
			if(vc[0].first!=vc[1].first)
				fg=1;
		}
		if(fg==1)
			cout<<"No"<<endl;
		else if(an<=2&&fg==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}	
}