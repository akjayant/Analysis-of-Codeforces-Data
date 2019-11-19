#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int N , K;
	cin>>N>>K;
	int tab[N];
	for (int i = 0 ; i < N ; i++)
	{
		cin>>tab[i];
	}
	sort(tab , tab + N);
	deque<pair<int , int> >prix;
	for (int i = 0 ; i < N / 2 ; i++)
	{
		prix.push_back({i + 1 , tab[i + 1] - tab[i]});
		if (N % 2 == 1 || i < N / 2 - 1) prix.push_back({i + 1 , tab[N - i - 1] - tab[N - i - 2]});
	}
	int diff = tab[N - 1] - tab[0];
	for (int i = 0 ; i < prix.size() ; i++)
	{
		//cout<<prix[i].first<<" "<<prix[i].second<<endl;
		if (K > prix[i].first * prix[i].second)
		{
			diff -= prix[i].second;
			K -= prix[i].first * prix[i].second;
		}
		else
		{
			diff -= (K / prix[i].first);
			K = 0;
			break;
		}
	}
	cout<<diff<<endl;
}