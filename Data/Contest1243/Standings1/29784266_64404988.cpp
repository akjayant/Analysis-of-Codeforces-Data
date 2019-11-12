#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pi 3.1415926535897932
#define INF INT_MAX
#define MOD 1000000007

int main() {

	int T;
	cin>>T;
	while(T--)
	{
		int n,i,j,k,ans=0,l;
		cin>>n;
		string s,t;
		cin>>s;
		cin>>t;
		vector<pair<int,int> >v;
		map<int,int>mp;
		for(i=0;i<n;++i)mp[s[i]]++,mp[t[i]]++;
		l=0;
		for(auto e:mp)if(e.S%2){cout<<"NO\n";l=1;break;}
		if(l)continue;
		for(i=0;i<n;++i)
		{
			if(s[i]==t[i])continue;
			l=0;
			for(j=i+1;j<n;++j)
			{
				if(s[i]==s[j])
				{
					swap(t[i],s[j]);
					v.push_back({j,i});
					l=1;
					break;
				}
			}
			if(l)continue;
			for(j=i+1;j<n;++j)
			{
				if(s[i]==t[j])
				{
					swap(t[j],s[i+1]);
					v.push_back({i+1,j});
					swap(s[i+1],t[i]);
					v.push_back({i+1,i});
					l=1;
					break;
				}
			}
		}
		if(s!=t){cout<<"NO\n";continue;}
		cout<<"YES\n"<<v.size()<<"\n";
		for(auto e:v)cout<<e.F+1<<" "<<e.S+1<<"\n";
	}

	return 0;
}