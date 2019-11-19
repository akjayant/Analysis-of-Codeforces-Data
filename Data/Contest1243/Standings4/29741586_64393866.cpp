#include <bits/stdc++.h>

using namespace std;

#define int long long

main()
{
	int n;
	cin >> n;
	
	vector <int> factori;
	
	if(n % 2 == 0)
	{
		while(n > 1 && n % 2 == 0)
		{
			n /= 2;
		}
		
		factori.push_back(2);
		
		if(n != 1)
		{
			cout << 1;
			return 0;
		}
		else
		{
			cout << 2;
			return 0;
		}
	}
	
	for(int i = 3; i * i <= n; i += 2LL)
		if(n % i == 0)
		{
			while(n > 1 && n % i == 0)
				n /= i;
			
			if(n > 1)
			{
				cout << 1;
				return 0;
			}
			
			cout << i;
			return 0;
		}
	
	cout << n;
}