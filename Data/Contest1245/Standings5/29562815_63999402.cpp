#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll MOD = 1e9+7;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int a,b,c;
		scanf("%d%d%d", &a, &b, &c);
		int br = 0;
		string s;
		for (int i=0 ; i<n ; i++) {
			char ch;
			scanf(" %c", &ch);
			//cout <<"ch = "<<ch<<endl;
			if (ch == 'R' and b) {
				b--;
				br++;
				s += 'P';
			} else if (ch == 'P' and c) {
				c--;
				br++;
				s += 'S';
			} else if (ch == 'S' and a) {
				a--;
				br++;
				s += 'R';
			} else {
				s += ' ';
			}
		}
		if (br*2 < n) {
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for (int i=0 ; i<n ; i++) {
			if (s[i]!=' ') continue;
			if (a) {
				a--;
				s[i] = 'R';
				continue;
			}
			if (b) {
				b--;
				s[i] = 'P';
				continue;
			}
			c--;
			s[i] = 'S';
		}
		printf("%s\n", s.c_str());
	}
	return 0;
}