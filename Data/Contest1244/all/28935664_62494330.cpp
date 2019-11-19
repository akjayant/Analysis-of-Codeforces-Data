#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1000001;
int tableau[MAXN];
int32_t main()
{
	int N , total;
	cin>>N>>total;
	int valeurActu = N  * (N + 1) / 2;
	if (valeurActu > total)
	{
		cout<<-1<<endl;
		exit(0);
	}
	int indice = 0;
	for (int i = 0 ; i < N ; i++)
	{
		tableau[i] = i + 1;
	}
	int plusGrand = 0;
	while (total - valeurActu > 0 && indice < N / 2)
	{
		//cout<<valeurActu<<endl;
		int dif = total - valeurActu;
		int posF = max(0LL , max(plusGrand , (N - indice - 1) - dif));
		valeurActu += (N - indice - 1) - posF;
		//cout<<N - indice -1<<" "<<posF<<endl;
		tableau[N - indice - 1] = tableau[posF];
		tableau[posF] = N - indice ;
		indice++;
		plusGrand = posF + 1;
		/*for (int i = 0 ; i < N ; i++)
		{
			cout<<tableau[i]<<" ";
		}
		cout<<endl;*/
	}
	cout<<valeurActu<<endl;
	for (int i = 0 ; i < N ; i++)
	{
		cout<<i + 1<<" ";
	}
	cout<<endl;
	for (int i = 0 ; i < N ; i++)
	{
		cout<<tableau[i]<<" ";
	}
	cout<<endl;
}