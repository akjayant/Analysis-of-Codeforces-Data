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
const int maxn = 300+10;
const int minn = -1e8-10;

ll a[maxn][maxn];

int main() {
	ll n;
	cin >> n;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(i & 1) {
			for(int j = n - 1; j >= 0; j--) {
				a[j][i] = ++cnt;
			}
		} else {
			for(int j = 0; j < n; j++) {
				a[j][i] = ++cnt;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(j != 0) {
				cout << " "; 
			}
			cout << a[i][j];
		}
		cout << endl;
	}
}