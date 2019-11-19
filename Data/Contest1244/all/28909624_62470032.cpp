#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define lowbit(x) ((x)&(-x))
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pdi pair<double,int>
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define Endl '\n'
#define caze(T) for(cin>>T;T;T--)
#define i16 __int128
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
string s;
int dep[2][1111],n;
int main()
{
	IOS;
	int QAQ;caze(QAQ)
	{
		cin>>n>>s;
		int ans=n;
		for(int j=0;j<n;++j)
			if(s[j]=='1')
				ans=max(ans,2*max(j+1,n-j));
		cout<<ans<<endl;
	}
}