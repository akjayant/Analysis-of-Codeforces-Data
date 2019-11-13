#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
const int N = 1e5+5, mod = 1e9+7;
int main()
{
	int n;
	cin >> n;
	vector<int> vec[n];
	int l = 1, r = n*n;
	if(n%2 == 0)
	{
		int cnt = 0;
		while(l <= r)
		{
			vec[cnt%n].push_back(l);
			vec[cnt%n].push_back(r);
			l++, r--;
			cnt++;
		}
	}
	if(n%2 == 1)
	{
		int cnt = 0;
		while(r-l+1 > n)
		{
			vec[cnt%n].push_back(l);
			vec[cnt%n].push_back(r);
			l++, r--;
			cnt++;
		}
		cnt = 0;
		for(int i=l; i<=r; i++) vec[cnt].push_back(i), cnt++;
	}
	for(int i=0; i<n; i++)
	{
	 	for(int j : vec[i]) cout << j << " ";
		cout << endl;
	}
}