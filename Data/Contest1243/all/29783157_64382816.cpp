/*input
5
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
3
adc
dac
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
		for(int i=0; i<26; i++)
		{
			raides1[i] = 0;
			raides2[i] = 0;
		}
		vector<int> poros;
		for(int i=0; i<n; i++)
		{
			if(a[i]!=b[i])
				poros.push_back(i);
		}
		if(poros.size()>2)
			cout << "No\n";
		else if (poros.size()==1)
			cout << "No\n";
		else
		{
			if((a[poros[0]]==b[poros[0]]) && (a[poros[1]]==b[poros[1]]))
				cout << "Yes\n";
			else if((a[poros[0]]==a[poros[1]]) && (b[poros[0]]==b[poros[1]]))
				cout << "Yes\n";
			else 
				cout << "No\n";

		}
	}
	return 0;
}