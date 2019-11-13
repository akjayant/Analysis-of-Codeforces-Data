#include <stdio.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#define i(x) scanf("%d",&x)
#define l(x) scanf("%lld",&x)
#define rep(a,b,c) for(int a = b;a<c;a++)
#define p pair<long long,long long>
using namespace std;
typedef long long ll;

int main() {
	int t; i(t);
	while (t--) {
		int n; i(n);
		char* ar1 = new char[n+1];
		char* ar2 = new char[n+1];
		cin >> ar1 >> ar2;
		int cnt = 0;
		int x = -1; int y = -1;
		rep(i, 0, n) {
			if (ar1[i] == ar2[i]) cnt++;
			else {
				if (x == -1) x = i;
				else y = i;
			}
		}
		if (cnt == n) {
			printf("Yes\n"); continue;
		}
		else if (cnt != n - 2) {
			printf("No\n"); continue;
		}
		if (ar1[x] == ar1[y] && ar2[x] == ar2[y]) printf("Yes\n");
		else printf("No\n");
	}
}