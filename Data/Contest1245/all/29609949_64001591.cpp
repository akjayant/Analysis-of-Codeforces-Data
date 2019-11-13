#include <bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	scanf("%d", &q);
	while (q--) { 
		int n, a, b, c;
		scanf("%d%d%d%d", &n, &a, &b, &c);
		string s = "";
		cin >> s;
		int won = 0;
		vector<int> output;
		output.clear();
		for (auto i : s) {
			// printf("%c\n", i);
			if (i == 'R') {
				if (b>0) {
					b--;
					output.push_back('P');
					won++;
				}
				else output.push_back(0);
			}
			if (i == 'P') {
				if (c > 0) {
					c--;
					output.push_back('S');
					won++;
				}
				else output.push_back(0);
			}
			if (i == 'S') {
				if (a > 0) {
					a--;
					output.push_back('R');
					won++;
				}
				else output.push_back(0);
			}
		}
		if (won * 2 >= n) {
			printf("YES\n");
			for (auto i : output) {
				if (i > 0) printf("%c", i);
				else {
					if (a > 0) {
						a--;
						printf("R");
					}
					else if (b > 0) {
						b--;
						printf("P");
					}
					else if (c > 0) {
						c--;
						printf("S");
					}
				}
			}
			printf("\n");
		}
		else printf("NO\n");
	}
	return 0;
}