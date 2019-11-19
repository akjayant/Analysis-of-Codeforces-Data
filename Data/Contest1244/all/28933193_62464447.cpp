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
		cin>>n>>m>>k>>l>>r;
		if(r>=n/k+(n%k!=0)+m/l+(m%l!=0))
		cout<<n/k+(n%k!=0)<<' '<<m/l+(m%l!=0);
		else
		cout<<-1;
		cout<<endl;
	}
	return 0;
}
