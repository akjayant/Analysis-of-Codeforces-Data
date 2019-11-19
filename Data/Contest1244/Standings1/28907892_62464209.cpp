#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define v vector<ll> 
#define vv vector<v>
#define p pair<ll,ll>
int main() {
	int t;
	cin>>t;
	while (t--)
	{
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int x=a/c;
		if (a%c!=0)
			x++;
		int y=b/d;
		if (b%d!=0)
			y++;
		if (x+y<=k)
			cout<<x<<" "<<y<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}