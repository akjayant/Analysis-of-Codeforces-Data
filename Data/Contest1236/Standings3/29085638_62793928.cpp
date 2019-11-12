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
	int n; sc(n);
	int ans[n][n];
	int t = 1;
	for (int j = 0; j < n; j++) {
		if (j%2) for (int i = 0; i < n; i++) ans[i][j]=t++;
		else for (int i = n-1; i+1; i--) ans[i][j]=t++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) printf("%d ", ans[i][j]);
		prif();
	}
	exit(0);
}
