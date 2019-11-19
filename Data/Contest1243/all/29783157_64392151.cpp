/*input
9
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	int saknis = sqrt(n);
	for(int i=2; i<=saknis; i++)
	{
		if(n%i==0)
		{
			int pirminis = i;
			while(n%pirminis==0)
			{
				n /= pirminis;
			}
			if(n==1)
			{
				cout << pirminis;
				return 0;
			}
			else
			{
				cout << 1;
				return 0;
			}
		}
	}
	cout << n;
	return 0;
}