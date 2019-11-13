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
		cin>>n;
		cin>>s>>t;
		vector<int> v;
		vector<int> u;
		for(int i=0;i<n;i++)
		{
			if(s[i]!=t[i])
			{
				v.pb(s[i]-'a');
				u.pb(t[i]-'a');
			}
		}
		if(!(v.size()==2 || v.size()==0))
		cout<<"No"<<endl;
		else
		{
			if(v[0]==v[1] && u[0]==u[1])
			cout<<"Yes"<<endl;
			else
			cout<<"No"<<endl;
		}
		
	}
}