#include<bits/stdc++.h>
#define ll long long
#define N 200050
#define pi acos(-1)
#define mod 1000000007
#define endl '\n'
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,-1,sizeof(x))
using namespace std;

ll t,n,p,w,d,r,a[N],ans,sum;
char s[N];

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	{
		cin>>n>>p>>w>>d;
		ans=1;
		for(ll i=p/w;i>=p/w-d;i--)
		if(i>=0&&(p-w*i)%d==0&&(p-w*i)>=0&&n-i-(p-w*i)/d>=0)
		{
			cout<<i<<' '<<(p-w*i)/d<<' '<<n-i-(p-w*i)/d;
			ans=0;
			break;
		}
		if(ans)
		cout<<-1;
		cout<<endl;
	}
	return 0;
}
