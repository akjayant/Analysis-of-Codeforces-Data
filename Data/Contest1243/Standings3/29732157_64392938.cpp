#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define sz size()
#define mp make_pair
#define int long long int
#define double long double
#define bp __builtin_popcountll
#define inf 1000000000000000000
#define f(i,a,b) for(int i=a;i<=b;i++)
#define r(i,a,b) for(int i=a;i>=b;i--)
const int M=1e9+7;
const int N=1e5+5;

int32_t main()
{
	FAST
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		string s,t;
		cin>>n>>s>>t;
		
		vector<pair<int,int> > ans;
		int f1[26]={0},f2[26]={0};
		for(int i=0;i<n;i++)
		{
			f1[s[i]-'a']++;
			f2[t[i]-'a']++;
		}
		int hh=0;
		
		for(int i=0;i<26;i++)
		{
				if(((f1[i]+f2[i])%2)==1)
				{
					hh=1;
					cout<<"No"<<endl;
					//cout<<s<<endl;
					break;
				}
		}
		if(hh==0)
		{
			cout<<"Yes"<<endl;
			//cout<<s<<endl;
			for(int i=0;i<n;i++)
			{
				if(s[i]==t[i])
				{}
				else
				{
				int f=0;
				for(int j=i+1;j<n;j++)
				{
					if(s[j]==s[i])
					{
						ans.pb(mp(j+1,i+1));
						swap(s[j],t[i]);
						f=1;
						break;
					}
				}
				if(f==0)
				{
					for(int j=i+1;j<n;j++)
					{
						if(s[i]==t[j])
						{
							swap(s[j],t[j]);
							swap(s[j],t[i]);
							ans.pb(mp(j+1,j+1));
							ans.pb(mp(j+1,i+1));
							break;
						}
					}
				}
				}
				
			}
			cout<<ans.size()<<endl;
			for(int x=0;x<ans.size();x++)
			cout<<ans[x].ff<<" "<<ans[x].ss<<endl;
			
			
		}
		
		
	}
}