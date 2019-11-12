#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int a[n];
		for(int i=0; i<n; i++) cin >> a[i];
		sort(a, a+n);
		reverse(a, a+n);
		int cnt = n;
		for(int i=0; i<n; i++)
		{
			if(a[i] < i+1)
			{
				 cnt = i;
				 break; 
			}
		}
		cout << cnt << endl;
	}
}