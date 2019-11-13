/*input
4
5
4 3 1 4 5
4
4 4 4 4
3
1 1 1
5
5 5 1 1 5
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k;
	cin >> k;
	while(k--)
	{
		int n;
		cin >> n;
		int a[n];
		for(int i=0; i<n; i++)
			cin >> a[i];
		sort(a, a+n);
		int ats = 1;
		for(int i=0; i<n; i++)
		{
			ats = max(ats, min(n-i, a[i]));
		}
		cout << ats << "\n";
	}
	return 0;
}