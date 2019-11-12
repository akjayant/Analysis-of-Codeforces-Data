#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
int main()
{
	int w;
	cin >> w;
	while(w--)
	{
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		int cnt[128];
		memset(cnt, 0, sizeof cnt);
		for(int i=0; i<n; i++) cnt[s[i]]++, cnt[t[i]]++;
		int f = 0;
		for(int i=0; i<n; i++)
		{
			if(cnt[s[i]]%2 == 1 || cnt[t[i]]%2 == 1) f = 1;
		}
		if(f) cout << "No" << endl;
		else
		{
			cout << "Yes" << endl;
			vector<pair<int, int>> vec;
			for(int i=0; i<n; i++)
			{
				if(s[i] == t[i]) continue;
				for(int j=i+1; j<n; j++)
				{
					if(s[i] == s[j])
					{
						vec.push_back({j, i});
						swap(s[j], t[i]);
						break;
					}
					if(t[i] == t[j])
					{
						vec.push_back({i, j});
						swap(s[i], t[j]);
						break;
					}
					if(s[i] == t[j])
					{
						vec.push_back({i+1, j});
						vec.push_back({i+1, i});
						swap(s[i+1], t[j]);
						swap(s[i+1], t[i]);
						break;
					}
					if(t[i] == s[j])
					{
						vec.push_back({j, i+1});
						vec.push_back({i, i+1});
						swap(s[j], t[i+1]);
						swap(s[i], t[i+1]);
						break;
					}
				}
			}
			cout << vec.size() << endl;
			for(auto p : vec) cout << p.f+1 << " " << p.s+1 << endl;
		}
	}
}