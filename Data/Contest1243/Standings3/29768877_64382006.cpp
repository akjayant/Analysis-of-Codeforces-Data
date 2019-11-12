#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 10;
int T,n;
char s[maxn],t[maxn];
int stk[maxn],top;

int main()
{
	cin >> T;
	while(T--)
	{
		cin >> n;
		scanf("%s%s",s,t);
		top = 0;
		for(int i = 0; i < n; i++)
		{
			if(s[i] != t[i])
			{
				stk[top++] = i;
			}
		}
		if(top > 2 || top == 1)
		{
			cout << "No" << endl;
			continue;
		}
		if(top == 0)
		{
			cout << "Yes" << endl;
			continue;
		}
		if(s[stk[1]] == s[stk[0]] && t[stk[1]] == t[stk[0]])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}

