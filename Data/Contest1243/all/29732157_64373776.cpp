#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define sz size()
#define mp make_pair
#define int long long int
#define double long double
#define bp __builtin_popcountll
#define inf 1000000000000000000
#define f(i,a,b) for(int i=a;i<=b;i++)
#define r(i,a,b) for(int i=a;i>=b;i--)
const int M=1e9+7;
const int N=1e5+5;

int32_t main()
{
	FAST
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		cin>>n;
		int a[n],f[1005]={0};
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			f[a[i]]++;
		}
		for(int i=1000;i>=0;i--)
		{
			f[i]=f[i+1]+f[i];
		}
		for(int i=1000;i>=0;i--)
		{
			if(f[i]>=i)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
}