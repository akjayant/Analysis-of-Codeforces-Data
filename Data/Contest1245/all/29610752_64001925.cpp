#include <bits/stdc++.h>
using namespace std;
void LSH()
{
	#ifndef ONLINE_JUDGE
		freopen("1245A.INP","r",stdin);
		freopen("1245A.OUT","w",stdout);
	#endif // ONLINE_JUDGE
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
long long t,a,b,m;
int main()
{
	LSH();
	cin>>t;
	for ( int i = 1 ; i <= t ; ++i )
	{
		cin>>a>>b;
		m=__gcd(a,b);
		//cout<<m<<'\n';
		if ( m == 1 ) cout<<"Finite";
		else cout<<"Infinite";
		cout<<'\n';
	}
}