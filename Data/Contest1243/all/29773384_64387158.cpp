#include <bits/stdc++.h>

using namespace std ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	long long n ;
	cin>>n ;
	vector<long long>v ;
	for(long long i = 2ll ; i * i <= n ; ++i)
	{
		if(n%i == 0)
			v.push_back(i) ;
		while(n%i == 0)
			n /= i ;
	}
	if(n > 1)
		v.push_back(n) ;
	if(v.size() == 1)
		return cout<<v[0]<<"\n" , 0 ;
	return cout<<1<<"\n" , 0 ;
}