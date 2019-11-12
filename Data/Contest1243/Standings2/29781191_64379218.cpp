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
		int f=0;
		for(int i=0;i<n;i++)
			if(s[i]!=s1[i])f++;
		if(f!=2 and f!=0){
			cout<<"No"<<endl;
			continue;
		}
		else
		{
			if(f==0)
			{
				cout<<"Yes"<<endl;
				continue;
			}
			vector<int>v;
			for(int i=0;i<n;i++)
				if(s[i]!=s1[i])
					v.pb(i);
			string s3=s,s4=s1;
			s3[v[0]]=s1[v[1]];
			s4[v[1]]=s[v[0]];
			string s5 = s,s6=s1;
			s5[v[1]]=s1[v[0]];
			s6[v[0]]=s[v[1]];
			//cout<<s3<<" "<<s4<<endl;
			if(s3!=s4 or s5!=s6)
				cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}
	}
}