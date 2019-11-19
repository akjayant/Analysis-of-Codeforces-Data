#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define MAXN 100100 
ll n, m, cnt1, cnt2, p, q, cnt3, cnt4, t; 
int main()
{
	cin>>t;
	while(t--)
	{
		cnt1=cnt2=cnt3=cnt4=0;
		cin>>n;
		for(int i=1;i<=n;i++) 
		{
			cin>>p;
			if(p%2 == 1) cnt1++;
			else cnt2++;
		}
		cin>>m;
		for(int i=1;i<=m;i++) 
		{
			cin>>p;
			if(p%2 == 1) cnt3++;
			else cnt4++;
		}
		ll ans=0;
		ans = (cnt3*cnt1) + (cnt2*cnt4);
		cout<<ans<<endl;
	}
		
	return 0;
} 
