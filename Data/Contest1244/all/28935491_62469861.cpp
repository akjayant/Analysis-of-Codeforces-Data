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
		int n;
		cin>>n;
		int ans =  n;
		string s;
		cin>>s;
		fl(i,0,n)
		{
			if(s[i] == '1')
			{
				ans = max(ans,(i+1)*2);
				ans = max(ans,(n-i)*2);
			}
		}
		cout<<ans<<endl;
	}
}