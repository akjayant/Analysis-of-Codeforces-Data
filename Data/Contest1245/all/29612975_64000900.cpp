#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int nbJeux;
	cin >> nbJeux;
	int pierre , papier , ciseaux;
	cin >> pierre >> papier >> ciseaux;
	string jeu;
	cin >> jeu;
	string moi = jeu;
	int nbVictoires = 0;
	for (int iJeu = 0 ; iJeu < nbJeux ; iJeu++)
	{
		if (jeu[iJeu] == 'R')
		{
			if (papier > 0)
			{
				jeu[iJeu] = 'P';
				papier--;
				nbVictoires++;
			}
			else
			{
				jeu[iJeu] = 'N';
			}
		}
		else if (jeu[iJeu] == 'P')
		{
			if (ciseaux > 0)
			{
				ciseaux--;
				nbVictoires++;
				jeu[iJeu] = 'S';
			}
			else
			{
				jeu[iJeu] = 'N';
			}
		}
		else
		{
			if (pierre > 0)
			{
				pierre--;
				nbVictoires++;
				jeu[iJeu] = 'R';
			}
			else
			{
				jeu[iJeu] = 'N';
			}
		}
	}
	if (nbVictoires < ((nbJeux + 1) / 2))
	{
		cout << "NO" << endl;
		return;
	}
	cout <<"YES" <<endl;
	for (int i = 0 ; i < nbJeux ; i++)
	{
		if (jeu[i] == 'N')
		{
			if (pierre > 0)
			{
				cout << "R";
				pierre--;
			}
			else if (ciseaux > 0)
			{
				cout<<"S";
				ciseaux--;
			}
			else
			{
				cout<<"P";
				papier--;
			}

		}
		else
		{
			cout<<jeu[i];
		}
	}
	cout<<endl;
}
int main()
{
	int T;
	cin >> T;
	for (int i = 0 ; i < T ; i++)
	{
		solve();
	}
}