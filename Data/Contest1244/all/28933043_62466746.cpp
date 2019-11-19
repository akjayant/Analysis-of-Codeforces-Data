#include <bits/stdc++.h>

using namespace std;
#define fr(i,x,y) for(int i=x;i<y;i++)
//#define int long long
const int N=1e6,INF=1e9;
int mas[N];
void solve()
{
	int a,b,c,d,k;
	cin>>a>>b>>c>>d>>k;
	if(a/c+(int)(a%c>0)+b/d+int(b%d>0)<=k)cout<<(a/c)+int(a%c>0)<<' '<<b/d+int(b%d>0)<<'\n';
	else cout<<-1<<'\n';
}
 main()
{
	int t;
	cin>>t;
	while(t--)solve();
}