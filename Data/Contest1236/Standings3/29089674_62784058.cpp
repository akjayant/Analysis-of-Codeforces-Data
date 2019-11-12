#include<bits/stdc++.h>
#define ll long long
#define N 1000050
#define pi acos(-1)
#define mod 1000000007
#define endl '\n'
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,-1,sizeof(x))
using namespace std;

ll t,n,k,l,r,a[N],b[N],ans,sum;
char s[N];

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--)
	{
		cin>>t>>l>>r;
		ans=0;
		ans=min(l,r/2);
		l-=ans;
		ans+=min(t,l/2);
		cout<<ans*3<<endl;
	}
	return 0;
}
