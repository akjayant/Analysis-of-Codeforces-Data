#include <bits/stdc++.h>

using namespace std;
#define fr(i,x,y) for(int i=x;i<y;i++)
//#define int long long
const int N=1e6,INF=1e9;
void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int q1=-1,q2=-1;
	fr(i,0,s.size())
	{
		if(s[i]=='1')
		{
			if(q1==-1)q1=i;
			q2=i;
		}
	}
	if(q1==-1)cout<<n<<'\n';
	else
	{
		cout<<max((q2+1)*2,(n-q1)*2)<<'\n';
	}
}
 main()
{
	int t;
	cin>>t;
	while(t--)solve();
}