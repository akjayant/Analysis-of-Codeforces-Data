#include <bits/stdc++.h>
using namespace std;
#define int long long
struct point
{
	int x , y;
};

struct pr_dist
{
	int dist;
	int type;
	int autreVille;
};
int32_t main()
{
	int nbVilles;
	cin >> nbVilles;
	point villes[nbVilles];
	for (int i = 0 ; i < nbVilles ; i++)
	{
		cin >> villes[i].x >> villes[i].y;
	}
	int coutMettre[nbVilles];
	int coutConnecter[nbVilles];
	for (int i = 0 ; i < nbVilles ; i++)
	{
		cin >> coutMettre[i];
	}
	for (int i = 0 ; i < nbVilles ; i++)
	{
		cin >> coutConnecter[i];
	}
	pr_dist distanceActu[nbVilles];
	int coutTotal = 0LL;
	for (int i = 0 ; i < nbVilles ; i++)
	{
		distanceActu[i].type = 0;
		distanceActu[i].dist = coutMettre[i];
	}
	vector <int> allumer;
	vector <pair<int , int> > connecter;
	for (int i = 0 ; i < nbVilles ; i++)
	{
		int distCompo = 1e18;
		int indice = 0;
		for (int iVille = 0 ; iVille < nbVilles ; iVille ++)
		{
			if (distanceActu[iVille].dist != -1 && distCompo > distanceActu[iVille].dist)
			{
				indice = iVille;
				distCompo = distanceActu[iVille].dist;
			}
		}
		coutTotal += distCompo;
		distanceActu[indice].dist = -1;
		if (distanceActu[indice].type == 0)
		{
			allumer.push_back(indice);
		}
		else
		{
			connecter.push_back({indice , distanceActu[indice].autreVille});
		}
		for (int iVille = 0 ; iVille < nbVilles ; iVille ++)
		{
			if (distanceActu[iVille].dist == -1)
			{
				continue;
			}
			int nouveauCout = (coutConnecter[iVille] + coutConnecter[indice]) * (abs(villes[indice].x - villes[iVille].x) + abs(villes[indice].y - villes[iVille].y));
			if (nouveauCout < distanceActu[iVille].dist)
			{
				distanceActu[iVille].dist = nouveauCout;
				distanceActu[iVille].type = 1;
				distanceActu[iVille].autreVille = indice;
			}
		}

	}
	cout<<coutTotal<<endl;
	cout<<allumer.size()<<endl;
	for (int i = 0 ; i < allumer.size() ; i++)
	{
		cout<<allumer[i] + 1<<" ";
	}
	cout<<endl;
	cout<<connecter.size()<<endl;
	for (int i = 0 ; i < connecter.size() ; i++)
	{
		cout<<connecter[i].first + 1<<" "<<connecter[i].second + 1<<endl;
	}
}