#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define ii pair<int,int> 
using namespace std;
const int MAXN = 10000;
int T, n;
string s, t;
int main() {
	int T;
	cin >> T;
	while (T--)
	{
		vector<ii> Ans;
		Ans.clear();
		cin >> n;
		cin >> s;
		cin >> t;
		for (int i = 0; i < s.length() - 1; ++i)
		{
			if (s[i] != t[i])
			{

				bool flag = false;
				for (int j = i + 1; j < s.length(); ++j)
				{
					if (s[j] != t[j])
					{
						if (t[j] == t[i])
						{
							swap(s[i], t[j]);
							Ans.push_back(ii(i, j));
							flag = true;
							break;
						}
						else
							if (s[j] == t[i])
							{
								swap(s[j], t[j]);
								swap(s[i], t[j]);
								Ans.push_back(ii(j, j));
								Ans.push_back(ii(i, j));
								flag = true;
								break;
							}
					}
				}

				if (flag == false) break;
			}
		}

		if (s == t)
		{
			cout << "Yes\n";
			cout << Ans.size() << "\n";
			for (int i = 0; i < Ans.size(); ++i)
				cout << Ans[i].first + 1 << " " << Ans[i].second + 1 << "\n";

		}
		else
			cout << "No\n";

	}
	return 0;
}