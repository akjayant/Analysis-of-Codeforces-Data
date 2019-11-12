/*input
4
5
souse
houhe
3
cat
dog
2
aa
az
3
abc
bca

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int k;
	cin >> k;
	while(k--)
	{
		int n;
		cin >>n;
		string a, b;
		cin >> a >> b;
		int raides1[26], raides2[26];
		vector<pair<int, int> > keitimai;
		for(int i=0; i<n; i++)
		{
			if(a[i]!=b[i])
			{
				for(int j=i+1; j<n; j++)
				{
					if(a[j]==a[i])
					{
						swap(a[j], b[i]);
						keitimai.push_back(make_pair(j, i));
						break;
					}
					if(a[i]==b[j])
					{
						swap(b[j], a[j]);
						swap(a[j], b[i]);
						keitimai.push_back(make_pair(j, j));
						keitimai.push_back(make_pair(j, i));
						break;
					}
				}
			}
		}
		int pavyko = 1;
		for(int i=0; i<n; i++)
		{
			if(a[i]!=b[i])
				pavyko = 0;
		}
		if(pavyko)
		{
			cout << "Yes\n" << keitimai.size() << "\n";
			for(int i=0; i<keitimai.size(); i++)
			{
				cout << keitimai[i].first+1 << " " << keitimai[i].second+1 << "\n";
			}

		}
		else 
			cout << "No\n";
		/*for(int i=0; i<26; i++)
		{
			raides1[i] = 0;
			raides2[i] = 0;
		}

		vector<int> poros;
		deque<int> anesutampantys[26];
		deque<int> bnesutampantys[26];
		for(int i=0; i<n; i++)
		{
			if(a[i]!=b[i])
			{
				anesutampantys[a[i]-'a'].push_back(i);
				bnesutampantys[b[i]-'a'].push_back(i);
			}
		}
		for(int i=0; i<26; i++)
		{
			if((anesutampantys[i].size()+bnesutampantys[i].size())%2!=0)
			{
				cout << "No\n";
				continue;
			}
		}
		for(int i=0; i<26; i++)
		{
			int pirmas = 0;
			int antras = 0;
			while(anesutampantys[i].size()>0)
			{

			}
		}*/
	}
	return 0;
}