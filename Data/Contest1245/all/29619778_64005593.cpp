#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--)
	{
		int n,a,b,c,win = 0;
		cin >> n;
		string s;
		cin >> a >> b >> c;
		cin >> s;
		s = " " + s;
		string ans = s;
		for(int i = 1;i <= n;i++)
			if(s[i] == 'R' && b)
				b--,win++,ans[i] = 'P';
			else if(s[i] == 'P' && c)
				c--,win++,ans[i] = 'S';
			else if(s[i] == 'S' && a)
				a--,win++,ans[i] = 'R';
		if(win < (n + 1) / 2)
		{
			cout << "NO\n";
			continue;
		}
		else
		{
			cout << "YES\n";
			for(int i = 1;i <= n;i++)
				if(ans[i] != s[i])
					cout << ans[i];
				else
				{
					if(a)
						cout << 'R',a--;
					else if(b)
						cout << 'P',b--;
					else
						cout << 'S',c--;
				}
			cout << '\n';
		}
	}
	return 0;
}