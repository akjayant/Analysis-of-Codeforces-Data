#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>

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

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int sol=0;
        for (int i=0; i<=100; ++i) {
            if (i>a || i*2>b) break;
            int ost=b-i*2;
            sol=max(sol, i*3+min(ost, c/2)*3);
        }
        printf("%d\n", sol);
    }
    return 0;
}
