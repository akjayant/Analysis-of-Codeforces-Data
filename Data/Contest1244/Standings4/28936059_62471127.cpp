#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a;
		string b;
		cin >> a >> b;
		int ans = a;
	
		for(int i = 0 ; i < b.size(); i ++)
			if(b[i] == '1')
			{
				ans = max({ans, (i+1)+(i+1), (i+1)+(a-i), (a-i)+(a-i)});
			}
		cout << ans << "\n";

	}
	
	
	return 0;
}