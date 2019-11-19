#include<bits/stdc++.h>
using namespace std;

#define test() int t;cin>>t;for(int tc=1;tc<=t;tc++)
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define nl cout<<"\n"

const int MAXN = 1005;
const int LOGN = 20;
const int INF = 1e9;

int main()
{

	test()
	{
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int x = (a+c-1)/c;
		int y = (b+d-1)/d;
		if( x + y <= k )
			cout<<x<<" "<<y,nl;
		else
			cout<<"-1\n";
	}

	return 0;
}