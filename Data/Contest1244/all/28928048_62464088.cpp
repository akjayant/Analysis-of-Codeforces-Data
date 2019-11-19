#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ld long double
#define f(i,x,n) for(int i=x;i<n;i++)
#define int long long
#define mod 1000000007
#define endl "\n"
#define MAXN 300001 
const int INF = 1e12;
void fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
int32_t main() 
{
	fastio();
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int a1=(a+c-1)/c,a2=(b+d-1)/d;
		if(a1+a2<=k)
			cout<<a1<<" "<<a2<<endl;
		else
			cout<<-1<<endl;
	}		
}