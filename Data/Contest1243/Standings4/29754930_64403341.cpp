#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

long long n;
vector <int> arr;
long long answer;

void In()
{
	cin >> n;
	answer = n;
}

void Solve()
{
	long long maximum = sqrt(n);
	for (int i = 2; i <= maximum; i++) if (n % i == 0)
	{
		answer = i;
		while (n % i == 0) n /= i;
		if (n == 1) return;
		else 
		{
			answer = 1;
			return;
		}
	}
}

void Out()
{
	cout << answer << endl;
}

int main()
{__
	In();
	Solve();
	Out();
}