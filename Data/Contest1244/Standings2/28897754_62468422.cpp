#include <bits/stdc++.h>
using namespace std;




int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n;
		string s;
		cin >> n >> s;
		
		int l = -1, r = -1;
		bool q = 1;
		
		for(int i = 0; i < n; i++)
		{
			if(s[i] == '1')
			{
				if(q) l = i + 1;
				q = 0;
				r = i + 1;
			}
		}
		if(l == -1) cout << n << endl;
		else cout << max(n - l + 1, r) * 2 << endl;
	}
	
	return 0;
}