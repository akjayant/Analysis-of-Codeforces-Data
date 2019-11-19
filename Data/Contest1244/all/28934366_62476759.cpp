#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
ll n, p, w, d, x, y, z;
ll gcd(ll x, ll y)
{
	if(y == 0) return x;
	else return gcd(y, x%y);
}
int main()
{
	cin>>n>>p>>w>>d;
	ll gg = gcd(w, d);
	if(p%gg != 0)
	{
		printf("-1\n");
		return 0;
	}
	p /= gg;
	w /= gg;
	d /= gg;
	ll cnt1=-1, cnt2=-1;
	for(int i=0;i<=w && i*d <= p;i++)
	{
		if((p-i*d)%w == 0)
		{
			cnt2 = i;
			break;
		}
	}
    cnt1 = (p-cnt2*d)/w;
	if(cnt1 + cnt2 > n || cnt2 == -1) 
	{
		printf("-1\n");
		return 0;
	}
	else
	{
		cout<<cnt1<<" "<<cnt2<<" "<<n-cnt1-cnt2<<endl;
	}
	
	return 0;
 } 
