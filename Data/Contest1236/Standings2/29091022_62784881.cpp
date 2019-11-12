#include <bits/stdc++.h>
 
using namespace std;
#define fr(i,x,y) for(int i=x;i<y;i++)
#define int long long
const int N=1e6,INF=1e9,MOD=100000001;
int mas[N];
void solve()
{

	int a,b,c;
	cin>>a>>b>>c;
	cout<<((min(b,c/2)+min(a,(b-min(b,c/2))/2)))*3<<'\n';
}
 main()
{
	int t;
	cin>>t;
	while(t--)solve();
}