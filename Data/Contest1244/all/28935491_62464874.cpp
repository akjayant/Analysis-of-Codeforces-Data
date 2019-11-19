#include <bits/stdc++.h> 
using namespace std;
#define fl(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007 
#define mx 100005
#define mx2 19
#define inf 1e9
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int x = a/c + (a%c!=0);
		int y = b
		/d + (b%d!=0);
		if(x+y<=k)
		{
			cout<<x<<" "<<y<<endl;
		}
		else cout<<-1<<endl;
	}
}