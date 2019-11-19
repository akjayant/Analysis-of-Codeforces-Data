#include <bits/stdc++.h>
#define int long long
#define pet pair<int,int>
#define one first
#define two second
using namespace std;

void solve()
{
	int n;
	cin >> n;
	
	int eve1=0,eve2=0;
	int odd1=0,odd2=0;
	
	int t;
	while(n--)
	{
		cin >> t;
		if(t%2==0)
		eve1++;
		
		else
		odd1++;
	}
	
	int m;
	cin >> m;
	
	while(m--)
	{
		cin >> t;
		if(t%2==0)
		eve2++;
		
		else
		odd2++;
	}
	cout << eve1*eve2+odd1*odd2 << endl;
	
}

main()
{
	int t;
	cin >> t;
	
	while(t--)
	solve();
}

