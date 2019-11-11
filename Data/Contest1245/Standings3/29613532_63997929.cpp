//#pragma GCC optimize(3)
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
typedef long long LL;
using namespace std;
#define MAXN 1000005
#define eps (1e-11)
#define lyh 19260817
#define njj 19491001
const double pi = acos(-1.0);
#define P pair<int,int>
//#define int LL

int gcd(int a, int b) {
      if (b == 0) {
             return a;
      }
      else {
             return gcd(b, a%b);
      }
}

signed main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b; scanf("%d%d", &a, &b);
		int temp = gcd(a, b);
		if (temp == 1) printf("Finite\n");
		else printf("Infinite\n");
	}
	return 0;
}