#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(NULL);

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

const int INT_INF = 1e9;
const ll LL_INF = 1e18;
const int MAXN = 500010;

typedef struct GE{
	int to;
	ll w;
}GE;

int n, m;
int A[303][303];
int main() {
	scanf("%d", &n);
		
	int f = 1;
	int st, ed, d;
	int num=1;
	for(int i=0;i<n;i++){
		if(f) st = 0, ed = n-1, d=1;
		else st = n-1, ed = 0, d=-1; 
		f = !f;
		int j = st;
		while(1) {
			A[j][i] = num++;
			if(j==ed) break;
			j += d;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d ", A[i][j]);
		puts("");
	}
	
	return 0;
}