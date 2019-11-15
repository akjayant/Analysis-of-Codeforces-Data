#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int N;
	cin>>N;
	for (int i = 0 ; i < N ; i++)
	{
		int a,b;
		cin>>a>>b;
		if (__gcd(a,b) == 1)
		{
			cout << "Finite" << endl;
		}
		else
		{
			cout << "Infinite" << endl;
		}
	}
}