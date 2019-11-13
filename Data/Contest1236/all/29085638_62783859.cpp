#include <bits/stdc++.h>
 
using namespace std;
 
#define sc(a) scanf("%d",&a)
#define sc2(a,b) sc(a), sc(b)
#define sc3(a,b,c) sc2(a, b), sc(c)
#define pri(x) printf("%d\n",x)
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define BUFF ios::sync_with_stdio(0)
#define prif() printf("\n")
#define prie(x) printf("%d ", x)
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
	int t; sc(t);
	while (t--) {
		int a, b, c; sc3(a, b, c);
		int ma = 0;
		for (int i = 0; i <= 100; i++) for (int j = 0; j <= 100; j++) {
			if (i>a) continue;
			if (2*i+j>b) continue;
			if (2*j>c) continue;
			ma = max(ma, i+2*i+j+2*j);
		}
		pri(ma);
	}
	exit(0);
}
