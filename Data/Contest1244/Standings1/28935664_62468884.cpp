#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int N;
	cin>>N;
	string S;
	cin>>S;
	int maxi = N;
	for (int i = 0 ; i < N ; i++)
	{
		if (S[i] == '1')
		{
			maxi = max(maxi , i + 1   + N - i);
			maxi = max(maxi , i + 1 + i + 1);

			maxi = max(maxi , N - i + N - i);
		}
	}
	cout<<maxi<<endl;
}
int main()
{
	int T;
	cin>>T;
	for (int i = 0 ; i < T ; i++)
	{
		solve();
	}
}