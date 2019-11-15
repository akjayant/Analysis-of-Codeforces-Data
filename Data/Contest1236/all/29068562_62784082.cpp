#include <algorithm>
#include  <iostream>
#include   <cstdlib>
#include   <cstring>
#include    <cstdio>
#include    <string>
#include    <vector>
#include    <bitset>
#include     <stack>
#include     <cmath>
#include     <deque>
#include     <queue>
#include      <list>
#include       <set>
#include       <map>
#define line printf("---------------------------\n")
#define mem(a, b) memset(a, b, sizeof(a))
#define pi acos(-1)
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const int mod = 1e9+7;
const int maxn = 2e5+10;
const int minn = -1e8-10;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int ans = min(c/2, b);
		b -= ans;
		ans += min(b / 2, a);
		ans *= 3;
		cout << ans << endl;
	}
}