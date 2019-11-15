/*suri_kumkaran*/

#include <bits/stdc++.h>

using namespace std;

#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define MP make_pair
#define EB emplace_back
#define endl "\n"
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long int int64;
typedef vector<int64> VI64;
typedef vector<pair<int64,int64>> VII64;
typedef vector<string> VS;
typedef vector<vector<int64>> VVI;

int main()
{
	IOS;
	int64 T=1;
	cin>>T;
	while(T--)
	{
		int64 n,i,j;
		string s1,s2;
		cin>>n;
		cin>>s1>>s2;
		map<char,int64> mp;
		VI64 v;
		for(i=0;i<n;i++)
		{
			mp[s1[i]]++;
			mp[s2[i]]++;
			if(s1[i]!=s2[i])
			{
				v.EB(i);
			}
		}
		bool b=false;
		for(auto x:mp)
		{
			if(x.S&1)
				b=true;
		}
		if(b)
		{
			cout<<"No"<<endl;
			continue;
		}
		VII64 ans;

		int64 m=v.size();
		for(i=0;i<m;i++)
		{
			if(s1[v[i]]==s2[v[i]])
				continue;
			b=true;
			for(j=i+1;j<m;j++)
			{
				if(s1[v[j]]==s2[v[j]])
					continue;
				if(s2[v[i]]==s2[v[j]])
				{
					b=false;
					swap(s1[v[i]],s2[v[j]]);
					ans.push_back({v[i]+1,v[j]+1});
					break;
				}
			}
			if(b)
			{
				for(j=i+1;j<m;j++)
				{
					if(s1[v[j]]==s2[v[j]])
					continue;
					if(s2[v[i]]==s1[v[j]])
					{
						swap(s1[v[j]],s2[v[j]]);
						ans.push_back({v[j]+1,v[j]+1});
						swap(s1[v[i]],s2[v[j]]);
						ans.push_back({v[i]+1,v[j]+1});
						break;
					}
				}
			}
		}

		if(s1==s2&&ans.size()<=2*n)
		{
			cout<<"Yes"<<endl;
			cout<<ans.size()<<endl;
			for(auto x: ans)
				cout<<x.F<<" "<<x.S<<endl;
		}
		else
			cout<<"No"<<endl;



	}

	return 0;
}