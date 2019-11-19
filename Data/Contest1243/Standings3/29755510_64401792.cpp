#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
vector<long long> v;
long long gcd(long long a,long long b)
{
	if(b>a)
		return gcd(b,a);
	else if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	long long g,i,n,sq;
	cin>>n;
	if(n==1)
	{
		cout<<1<<"\n";
		return 0;
	}
	sq=sqrtl(n);
	for(i=1;i<=sq;i++)
	{
		if(n%i==0)
		{
			v.push_back(i);
			if(i!=n/i)
				v.push_back(n/i);
		}
	}
	sort(v.begin(),v.end());
	g=0;
	for(i=1;i<v.size();i++)
	{	
		g=gcd(g,v[i]);
		if(g==1)
			break;
	}
	cout<<g<<"\n";
	return 0;
}
