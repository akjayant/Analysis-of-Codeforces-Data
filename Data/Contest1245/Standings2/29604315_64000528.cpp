#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<assert.h>
#include<functional>
using namespace std;

#define INF 1234567890
#define ll long long

int T;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--)
	{
		int N, R, P, S, cnt = 0;
		string s, res;
		cin >> N >> R >> P >> S >> s;
		for (int i = 0; i < N; i++)
		{
			if (s[i] == 'R' && P) res += 'P', P--, cnt++;
			else if (s[i] == 'P' && S) res += 'S', S--, cnt++;
			else if (s[i] == 'S' && R) res += 'R', R--, cnt++;
			else res += ' ';
		}
		for (int i = 0; i < N; i++)
		{
			if (res[i] == ' ')
			{
				if (R) res[i] = 'R', R--;
				else if (P) res[i] = 'P', P--;
				else if (S) res[i] = 'S', S--;
			}
		}
		if (cnt >= (N + 1) / 2) cout << "YES\n" << res << "\n";
		else cout << "NO\n";
	}
	return 0;
}