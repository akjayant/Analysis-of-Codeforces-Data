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
		char alp[27];
		memset(alp, 0, sizeof(alp));
		rep(i, 0, n) {
			alp[ar1[i] - 'a']++;
			alp[ar2[i] - 'a']++;
		}
		bool b = true;
		rep(i, 0, 27) {
			if (alp[i] % 2 == 1) {
				b = false; break;
			}
		}
		if (!b) {
			printf("No\n"); continue;
		}
		int an = 0;
		vector<pair<int, int>> ans;
		rep(i, 0, n) {
			if (ar1[i] == ar2[i]) continue;
			char x = ar1[i];
			int ind = -1;
			rep(j, i + 1, n) {
				if (ar1[j] == x) {
					ind = j; break;
				}
			}
			if (ind != -1) {
				an++; ans.push_back({ ind + 1,i+1});
				ar1[ind] = ar2[i];
				ar2[i] = x;
				continue;
			}
			rep(j, i + 1, n) {
				if (ar2[j] == x) {
					ind = j; break;
				}
			}
			an += 2;
			ans.push_back({ ind + 1,ind + 1 });
			ans.push_back({ ind + 1,i + 1 });
			ar2[ind] = ar1[ind];
			ar1[ind] = ar2[i];
			ar2[i] = x;
		}
		printf("Yes\n");
		printf("%d\n", an);
		rep(i, 0, ans.size()) {
			printf("%d %d\n", ans[i].first, ans[i].second);
		}
	}
}