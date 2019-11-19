#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#define PII pair<int,int>
#define VI vector<int>
#define VII vector<PII>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define _for0(i, _, n) for(int i=_;i<n;++i)
#define _for1(i, _, n) for(int i=_;i<=n;++i)
#define for0(i, n) for(int i=0;i<n;++i)
#define for1(i, n) for(int i=1;i<=n;++i)
#define rfor0(i, n) for(int i=n-1;i>=0;i--)
#define rfor1(i, n) for(int i=n;i>=1;i--)
#define all(it, obj) for(auto it=(obj).begin();it!=(obj).end();++it)
#define all_(_, it, obj) for(auto it=_;it!=(obj).end();++it)
#define rall(it, obj) for(auto it=(obj).rbegin();it!=(obj).rend();++it)
#define rall_(_, it, obj) for(auto it=_;it!=(obj).rend();++it)
using namespace std;
typedef long long LL;
#define N 100005

int main ()
{
	int t; scanf("%d", &t);
	while ( t-- ) {
		int n, m;
		LL odd_n = 0, odd_m = 0;
		LL even_n = 0, even_m = 0;
		scanf("%d",&n);
		for0(i, n) {
			int x; scanf("%d",&x);
			if ( x%2 == 0 ) {
				even_n++;
			} else {
				odd_n++;
			}
		}
		scanf("%d",&m);
		for0(i, m) {
			int x; scanf("%d",&x);
			if ( x%2 == 0 ) {
				even_m++;
			} else {
				odd_m++;
			}
		}
		LL ans = even_n*even_m + odd_n*odd_m;
		printf("%lld\n", ans);
	}
	return (0);
}

