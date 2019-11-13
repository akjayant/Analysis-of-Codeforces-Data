/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <list>
#include <climits>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
const ll inf = 1e17;
const int mod = 1e9+7;

int a, b;

int gcd(int x, int y) {
    if(x < y) swap(x, y);
    if(y == 0) return x;
    else return gcd(y, x%y);
}

void solve() {
    int d = gcd(a, b);
    if(d == 1) {
        printf("Finite\n");
    } else {
        printf("Infinite\n");
    }
}

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &a, &b);
        //printf("Case #%d: %lld\n", ++kase, solve());
        solve();
    }
	return 0;
}
