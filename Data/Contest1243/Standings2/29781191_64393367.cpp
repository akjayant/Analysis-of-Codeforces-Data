/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
*/
#include<bits/stdc++.h>
using namespace std;
#define testcase(t) int t;cin>>t;while(t--)
#define pb push_back
#define eb emplace_back
#define ll long long int
#define int long long
#define double long double
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define endl "\n"
#define imax INT_MAX
#define imin INT_MIN
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
int nod(int n)
{
	string s = to_string(n);
	return (int)s.length();
}
int32_t main()
{
	IOS
	//n==1
	testcase(t)
	{
		int n;
		cin>>n;
		string s,s1;
		cin>>s>>s1;
		int a[26]={0};
		for(int i=0;i<n;i++)
			a[s[i]-'a']++,a[s1[i]-'a']++;
		int f=0;
		for(int i=0;i<26;i++)
			if(a[i]%2)
				f=1;
		if(f)
		{
			cout<<"No"<<endl;
			continue;
		}
		cout<<"Yes"<<endl;
		std::vector<pair<int,int>> v;
		for(int i=0;i<n;i++)
		{
			if(s[i]!=s1[i])
			{
				int ind = 0;
				for(int j=i+1;j<n;j++)
					if(s1[j]==s[i] and s1[j]!=s[j]){
						ind=j;
						break;
					}
				if(ind){
				swap(s1[ind],s[ind]);
				swap(s1[i],s[ind]);
				v.pb({ind+1,ind+1});
				v.pb({ind+1,i+1});
				continue;
				}
				for(int j=i+1;j<n;j++)
				{
					if(s[j]==s[i])
					{
						ind=j;break;
					}
				}
				swap(s1[i],s[ind]);
				v.pb({ind+1,i+1});
			}
		}
		cout<<v.size()<<endl;
		for (int i = 0; i < v.size(); ++i)
		{
			/* code */cout<<v[i].first<<" "<<v[i].second<<endl;
		}
	}
}	