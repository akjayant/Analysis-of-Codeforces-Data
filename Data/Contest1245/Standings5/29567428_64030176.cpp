#include <iostream>
using namespace std;
int cd,ok[300],cnt[300],result[300],kq1;
char kq[12334];
int main()
{
				int t;
				cin >> t;
				while (t--)
				{
		cin >> cd;
		string s;
		kq1 = 0;
		cin >> cnt['R'] >> cnt['P'] >> cnt['S'];
		cin >> s;
		s = '0' + s;
		for (int i = 1 ; i< 300 ; i++)
		{
				result[i] = 0;
				kq[i] ='A';
		}
		for (int i = 1 ; i <= cd ; i++)
		{
				result[s[i]]++;
		}
		ok['R'] = 'P';
		ok['P'] = 'S';
		ok['S'] = 'R';
		kq1 += min(cnt['P'] , result['R']);
		kq1 += min(cnt['R'], result['S']);
		kq1 += min(cnt['S'] , result['P']);
		int need = cd / 2 + cd % 2;
		char mx = 'R';						if (cnt[mx] < cnt['R'])
						{
								mx = 'R';
						}						
						if (cnt[mx] < cnt['P'])
						{
								mx = 'P';
						}						
						if (cnt[mx] < cnt['S'])
						{
								mx = 'S';
						}

		if (kq1 >= need)
		{
				cout <<"YES"<<endl;
				for (int i = 1 ; i <= cd ; i++)
				{
						if (cnt[ok[s[i]]] != 0)
						{
								cnt[ok[s[i]]]--;
								char c = ok[s[i]];
								kq[i] = c;
						}
				}
				for (int i = 1 ; i <= cd ; i++)
				{
						if (kq[i] != 'R' && kq[i] != 'S' && kq[i] != 'P')
						{
								if (cnt['R'] != 0)
								{
										cnt['R']--;
										kq[i] = 'R';
								}
								else
								if (cnt['P'] != 0)
								{
										cnt['P']--;
										kq[i] = 'P';
								}
								else
								{
										cnt['S']--;
										kq[i] = 'S';
								}
						}
				}
				for (int i = 1 ; i <= cd ; i++) cout <<kq[i];
				cout <<'\n';
		}
		else cout <<"NO"<<'\n';
				}
}
