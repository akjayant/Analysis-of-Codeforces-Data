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
const int N=1e4+5;

int n;
char s1[N], s2[N];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%s %s", s1, s2);
        int a=-1, b=-1, cnt=0;
        for (int i=0; i<n; ++i) {
            if (s1[i]!=s2[i]) {
                ++cnt;
                if (a==-1) a=i;
                else b=i;
            }
        }
        if (cnt>2 || cnt==1) {
            printf("No\n");
            continue;
        }
        if (cnt==2) {
            if (s1[a]==s1[b] && s2[a]==s2[b]) printf("Yes\n");
            else printf("No\n");
            continue;
        }
    }
    return 0;
}
