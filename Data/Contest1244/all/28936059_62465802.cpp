#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, c, d,k;
		cin >> a >> b >> c >> d >> k;
		int t1 =  (a +c-1) / c;
		int t2 =  (b+d-1) / d;
		if(t1 + t2 > k)
			cout << -1 << endl;
		else
			cout << t1 << " " << t2 << endl;

	}
	
	
	return 0;
}