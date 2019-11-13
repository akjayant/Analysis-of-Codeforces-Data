#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int alph[26]={0}, n, i, flag=0, j, k, x, y;
		cin >> n;
		string S1, S2;
		cin >> S1 >> S2;
		char s1[n], s2[n];
		vector<pair<int, int>> ans;
		for(i=0; i<n; i++)
		{
			s1[i] = S1[i];
			s2[i] = S2[i];
		}

		for(i=0; i<n; i++)
		{
			// cout << s1[i]-97 << "KK\n";
			alph[s1[i]-97]++;
			alph[s2[i]-97]++;
		}

		for(i=0; i<26; i++)
		{
			if(alph[i]%2 != 0)
				flag = 1;
		}

		// for(i=0; i<26; i++)
		// 	cout << alph[i] << " ";
		// cout << "\n";

		if(flag == 1)
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";

		for(i=0; i<n; i++)
		{
			int flag = 0;
			if(s1[i] == s2[i])
				continue;

			for(j=i+1; j<n; j++)
			{
				if(s2[j] == s2[i])
				{
					char temp = s2[j];
					s2[j] = s1[i];
					s1[i] = temp;
					flag = 1;

					pair<int, int> ttemp;
					ttemp.first = i+1;
					ttemp.second = j+1;

					ans.push_back(ttemp);
					break;
				}
			}

			if(flag == 1)
				continue;

			for(j=i+1; j<n; j++)
			{
				if(s1[j] == s2[i])
				{
					char temp = s1[j];
					s1[j] = s2[i+1];
					s2[i+1] = temp;

					pair<int, int> ttemp;
					ttemp.first = j+1;
					ttemp.second = i+2;

					temp = s2[i+1];
					s2[i+1] = s1[i];
					s1[i] = temp;

					pair<int, int> stemp;
					stemp.first = i+1;
					stemp.second = i+2;

					ans.push_back(ttemp);
					ans.push_back(stemp);
					break;
				}
			}


		}

		// for(i=0; i<n; i++)
		// 	cout << s1[i];
		// cout << "\n";
		// for(i=0; i<n; i++)
		// 	cout << s2[i];
		// cout << "\n";

		cout << ans.size() << "\n";

		for(i=0; i<ans.size(); i++)
		{
			cout << ans[i].first << " " << ans[i].second << "\n";
		}


	}
}