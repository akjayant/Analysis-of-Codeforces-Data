#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int DIM = 1e5 + 7;

int res[DIM];

int get(int l, int r)
{
	int p = r - l + 1;
	
	res[1] = 1;
	res[2] = 2;
	
	for(int i = 3; i <= p; i++)
		res[i] = (res[i - 2] + res[i - 1]) % mod;
	
	return res[p];
}

main()
{
	string s;
	cin >> s;
	
	int n = s.size();
	
	s = ' ' + s;
	
	int res = 1;
	
	for(int i = 1; i <= n; i++)
		if(s[i] == 'n' || s[i] == 'u')
		{
			int l = i;
			int r = i;
			
			while(r + 1 <= n && s[r + 1] == s[r])
			{
				r++;
			}
			
			res = (res * get(l, r)) % mod;
			
			i = r;
		}
		else
			if(s[i] == 'm' || s[i] == 'w')
				res = 0;
	
	cout << res;
}