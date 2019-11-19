#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a;
		string s;
		scanf("%d", &a);
		cin >>s;
		int sol = s.size();
		for (int a=1 ; a<=s.size() ; a++) {
			int l = -1;
			int r = -1;
			int br1 = 0;
			int br2 = 0;
			for (int i=0 ; i<a ; i++) {
				br1 += (s[i] == '1');
				if (s[i] == '1' and l == -1) {
					l = i+1;
				}
			}
			for (int i=a-1 ; i<s.size() ; i++) {
				br2 += (s[i] == '1');
				if (s[i] == '1') {
					r = i+1;
				}
			}
			if (l!=-1) {
				sol = max(sol, max(a-l+1+max(l, (int)s.size()-l+1), a+br1));
			}
			if (r!=-1) {
				sol = max(sol, max(r-a+1+max(r, (int)s.size()-r+1), (int)s.size()-a+1+br2));
			}
		}
		printf("%d\n", sol);
	}
	return 0;
}