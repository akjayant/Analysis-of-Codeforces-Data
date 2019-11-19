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
int main()
{
	int QAQ;caze(QAQ)
	{
		int a,b,c,d,e;cin>>a>>b>>c>>d>>e;
		int t1=(a+c-1)/c;
		int t2=(b+d-1)/d;
		if(t1+t2>e) cout<<-1<<endl;
		else cout<<t1<<' '<<t2<<endl;
	}
}