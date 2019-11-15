#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <int, pii> pip;
typedef pair <pii, int> ppi;

const int INF=0x3f3f3f3f;

int n;
int p[1005];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i=0; i<n; ++i) {
            scanf("%d", p+i);
        }
        sort(p, p+n); reverse(p, p+n);
        int sol=0;
        for (int i=0; i<n; ++i) {
            sol=max(sol, min(i+1, p[i]));
        }
        printf("%d\n", sol);
    }
    return 0;
}
