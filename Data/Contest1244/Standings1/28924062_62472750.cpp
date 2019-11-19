#include <iostream>
#include <cstdio>
using namespace std;

int t, n, c1, c2;
string a;
int main()
{
	int i;
	cin >> t;
	while (t--) {
		scanf("%d", &n);
		cin >> a;
		for (i = c1 = 0; i < n; i++, c1++) if (a[i] == '1') break;
		for (i = n - 1, c2 = 0; i >= 0; i--, c2++) if (a[i] == '1') break;
		if (i < 0) printf("%d\n", n);
		else printf("%d\n", (n - min(c1, c2)) * 2);
	}
    return 0;
}