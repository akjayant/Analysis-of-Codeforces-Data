#include<bits/stdc++.h>
#define ll long long
#define N 200050
#define pi acos(-1)
#define mod 1000000007
#define endl '\n'
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,-1,sizeof(x))
using namespace std;

ll t,n,m,k,l,r,a[N],ans,sum;
char s[N];

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		ans=0;
		for(ll i=0;i<n;i++)
		if(s[i]=='1')
		ans=max(ans,max(i+1,n-i));
		if(ans)
		cout<<ans*2;
		else
		cout<<n;
		cout<<endl;
	}
	return 0;
}
