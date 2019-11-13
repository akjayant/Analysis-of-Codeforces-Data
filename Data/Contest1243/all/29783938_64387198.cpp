#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main()
{
	int k;
	cin >> k;
	for (; k > 0; k--)
	{
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		queue<int> q;
		bool gflag = false;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == t[i]) continue;
			bool flag = false;
			for (int j = i + 1; j < n; j++)
			{
				if (s[j] == s[i])
				{
					flag = true;
					q.push(j);
					q.push(i);
					s[j] = t[i];
					t[i] = s[i];
					break;
				}
				if (t[j] == s[i])
				{
					flag = true;
					q.push(j);
					q.push(j);
					q.push(j);
					q.push(i);
					t[j] = s[j];
					s[j] = t[i];
					t[i] = s[i];
					break;
				}
			}
			if (!flag)
			{
				gflag = true;
				break;
			}
		}
		if (gflag)
		{
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		cout << q.size() / 2 << "\n";
		while (!q.empty())
		{
			cout << q.front() + 1<< " ";
			q.pop();
			cout << q.front() + 1;
			q.pop();
			cout << "\n";
		}
	}
}