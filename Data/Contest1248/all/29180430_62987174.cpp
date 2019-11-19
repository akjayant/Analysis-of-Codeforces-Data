#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#define pii pair<int,int>
#define F first
#define S second
#define fr(i,n) for(int i=1;i<=n;++i)
#define pr cout<<
#define en <<'\n'
#define sp <<' '
using namespace std;
typedef long long ll;

int ar[200001];


main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m ;
	
	cin>>n ;
	fr(i,n)
	{
		cin>>ar[i];
	}
	sort(ar+1,ar+n+1);
	ll ans=0,sum=0;
	fr(i,n)
	{
		sum+=ar[i];
		if(i==n/2)
		{
			ans+=sum*sum;
			// pr sum en;
			sum=0;
		}
	}
	ans+=sum*sum;
	pr ans;
	
}






