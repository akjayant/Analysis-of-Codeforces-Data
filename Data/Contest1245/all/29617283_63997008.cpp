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
		cin>>l>>r;
		while(r)
		{
			t=l%r;
			l=r;
			r=t;
		}
		if(l==1)
		cout<<"Finite"<<endl;
		else
		cout<<"Infinite"<<endl;
	}
	return 0;
}
