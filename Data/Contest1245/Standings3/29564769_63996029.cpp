#include <bits/stdc++.h>
using namespace std;

#define int long long int

const int mod = 1e9+7;

#undef int
int main()
{
#define int long long int
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;
	while(t--)
	{
		int a, b;
		cin>>a>>b;
		if(__gcd(a, b) == 1)
			cout<<"Finite"<<endl;
		else
			cout<<"Infinite"<<endl;
	}

	return 0;
}