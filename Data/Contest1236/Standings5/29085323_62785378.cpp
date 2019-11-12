#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int, int>
using namespace std;

const int maxx = 1e7 + 5;
const double PI = acos(-1.0);
const long long inf = 0x3f3f3f3f;
const ll MAX = 1e15 + 5;

int n, m, T;

int a, b, c, ans;

int main(){
	int i, j, k;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d", &a, &b, &c);
		k = min(b, c / 2); ans = 3 * k;
		b -= k;
		ans += ( 3 * min(a, b / 2) );
		printf("%d\n", ans);
	}
	return 0;
}