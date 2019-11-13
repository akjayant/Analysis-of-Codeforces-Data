/*Author: ADITYA SHETH*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
#define t1(x)             cerr<<#x<<"="<<x<<endl
#define t2(x, y)          cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define t3(x, y, z)       cerr<<#x<<"=" <<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl
#define t4(a,b,c,d)       cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<endl
#define t5(a,b,c,d,e)     cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<endl
#define t6(a,b,c,d,e,f)   cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<" "<<#f<<"="<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
//freopen("output.txt","w",stdout);
//freopen("input.txt","r",stdin);
/*-------------------------------------------------------------------------------------------------------------------------------------*/
#define MOD 1000000007
#define endl "\n" 
#define int long long // remove when constraints are tight.
#define inf 1e18
#define ld long double
/*-------------------------------------------------------------------------------------------------------------------------------------*/

int32_t main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s,t;
		cin>>s>>t;
		int flag=1;
		vector<pair<int,int>> ans;
		while(true)
		{
			int f=0;
			for(int i=0;i<n;i++)
			{
				if(s[i]!=t[i])
				{	
					f=1;
					int f2=0;
					for(int j=i+1;j<n;j++)
					{
						if(s[j]!=t[j] && s[j]==s[i])
						{
							f2=1;
							ans.push_back({j,i});
							swap(s[j],t[i]);
							break;
						}
					}
					if(f2)
					{
						continue;
					}
					for(int j=i+1;j<n;j++)
					{
						if(s[j]!=t[j] && t[j]==s[i])
						{
							f2=1;
							ans.push_back({j,j});
							swap(s[j],t[j]);
							ans.push_back({j,i});
							swap(s[j],t[i]);
							break;
						}
					}
					if(f2==0)
					{
						f=0;
						flag=0;
						break;
					}
				}
			}
			if(f==0)
			{
				break;
			}
		}
		if(!flag)
		{
			cout<<"No\n";
			continue;
		}
		cout<<"Yes\n";
		//t(s,t);
		cout<<ans.size()<<endl;
		for(auto x: ans)
		{
			cout<<x.first+1<<" "<<x.second+1<<endl;
		}
	}
}
