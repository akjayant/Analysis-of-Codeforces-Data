#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
int t, n;
char s[55], p[55];
int a[27], k[27];
void Read() {
	scanf("%d", &n);
	scanf("%s%s", s, p);
	memset(a, 0, sizeof(a));
	memset(k, 0, sizeof(k));
	for (int i = 0; i < n; i++) a[s[i] - 'a']++;
	for (int i = 0; i < n; i++) k[p[i] - 'a']++;
}
typedef pair<int, int> pii;
vector<pii> res;
void gao() {
	res.resize(0);
	for (int i = 0; i < n; i++) {
		if (s[i] == p[i])
			continue;
		int g = -1;
		for (int j = i + 1; j < n; j++)
			if (s[j] == s[i]) {
				g = j;
				break;
			}
		//cout << "g " << g << '\n';
		if (g == -1) {
			for (int j = i + 1; j < n; j++)
				if (p[j] == s[i]) {
					g = j;
					break;
				}
			res.push_back(pii(g, g));
			swap(s[g], p[g]);
		}
		res.push_back(pii(g, i));
		swap(s[g], p[i]);
		//cout << s << ' ' << p << '\n';
	}
}
int main()
{
	scanf("%d", &t);
	while (t--) {
		Read();
		int i;
		for (i = 0; i < 26; i++) {
			if ((a[i] + k[i]) & 1)
				break;
		}
		if (i < 26) {
			printf("No\n");
			continue;
		}
		gao();
		printf("Yes\n%d\n", res.size());
		for (auto it : res)
			printf("%d %d\n", it.first + 1, it.second + 1);
	}
	return 0;
}
