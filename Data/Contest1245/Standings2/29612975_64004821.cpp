#include <bits/stdc++.h>
using namespace std;
const long long int MOD = (1000 * 1000 * 1000 + 7);
const long long int MAXN = (100 * 1000 + 10);

long long int nbPossibilites[MAXN];

int main()
{
	string message;
	cin >> message;
	for (int i = 0 ; i < message.size() ; i++)
	{
		if (message[i] == 'm' || message[i] == 'w')
		{
			cout<<0<<endl;
			return 0;
		}
	}
	nbPossibilites[0] = 1LL;
	for (int iPos = 0 ; iPos < message.size() ; iPos++)
	{
		nbPossibilites[iPos + 1] = nbPossibilites[iPos];
		if (iPos > 0 && message[iPos] == message[iPos - 1] && (message[iPos] == 'u' || message[iPos] == 'n'))
		{
			nbPossibilites[iPos + 1] += nbPossibilites[iPos - 1];
		}
		nbPossibilites[iPos + 1] %= MOD;
	}
	cout << nbPossibilites[message.size()] << endl;

}