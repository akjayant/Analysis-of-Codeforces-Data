// youngjinp20
// 2019 10

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<vi> vvi;

int main() {
	int T;
	cin >> T;
	for (int t=0; t<T; t++) {
		int n;
		int ct=0;
		int l=-1, r=-1;
		cin >> n;

		for (int i=0; i<n; i++) {
			int tmp;
			scanf("%1d", &tmp);
			if (l == -1 && tmp) l = i;
			if (tmp) r = i;
			if (tmp) ct ++;
		}


		if (l==-1 && r==-1) printf("%d\n", n);
		else printf("%d\n", max(n+ct, max((n-l)*2, (r+1)*2)));

	}

	return 0;
}
