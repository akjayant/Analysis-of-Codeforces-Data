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
int n;
string s,t;
int swap(char &a,char &b)
{
	char tt=a;
	a=b;
	b=tt;
}
int32_t main() 
{
	fastio();
	int k;
	cin>>k;
	while(k--)
	{
		cin>>n;
		cin>>s>>t;
		vector<pair<int,int>>vc;
		int aa[26];
		memset(aa,0,sizeof(aa));
		f(i,0,n)
		{
			aa[s[i]-'a']++;
			aa[t[i]-'a']++;
		}
		int fg=0;
		f(i,0,26)
		{
			if(aa[i]%2!=0)
				fg=1;
		}
		f(i,0,n)
		{
			if(s[i]!=t[i])
			{
				int ff=0;
				f(j,i+1,n)
				{
					if(s[j]==s[i])
					{
						vc.pb(mp(j+1,i+1));
						swap(s[j],t[i]);
						ff=1;
						break;
					}
				}
				if(ff==0)
				{
					f(j,i+1,n)
					{
						if(t[j]==s[i])
						{
							vc.pb(mp(n,j+1));
							swap(s[n-1],t[j]);
							vc.pb(mp(n,i+1));
							swap(s[n-1],t[i]);
							break;
						}
					}
				}
			}
		}
		if(fg==1)
			cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			cout<<vc.size()<<endl;
			f(i,0,vc.size())
			cout<<vc[i].first<<" "<<vc[i].second<<endl;
		}
	}	
}