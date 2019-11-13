#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100;

int q, n, a, b, c;
string s;
char h[MAXN + 1];

void runHand();

int main() {
	ios::sync_with_stdio(false);
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> n >> a >> b >> c >> s;
		runHand();
	}
}
void runHand() {
	int x = 0, y = 0, z = 0;
	memset(h, 0, sizeof h);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'R')
			x++;
		else if (s[i] == 'P')
			y++;
		else
			z++;
	}
	int t = min(a, z) + min(b, x) + min(c, y);
	if (t < n - t)
		cout << "NO\n";
	else {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'R' && b) {
				b--;
				h[i] = 'P';
			}
			else if (s[i] == 'P' && c) {
				c--;
				h[i] = 'S';
			}
			else if (s[i] == 'S' && a) {
				a--;
				h[i] = 'R';
			}
		}
		for (int i = 0; i < s.size(); i++)
			if (!h[i]) {
				if (a) {
					a--;
					h[i] = 'R';
				}
				else if (b) {
					b--;
					h[i] = 'P';
				}
				else {
					c--;
					h[i] = 'S';
				}
			}
		cout << "YES" << endl << h << endl;
	}
}
