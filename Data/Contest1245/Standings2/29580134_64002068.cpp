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

int n;
int a, b, c;
char s[110];

void solve() {
    char ans[110];
    memset(ans, 0, sizeof ans);
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == 'R' && b) {
            ans[i] = 'P';
            cnt++;
            b--;
        } else if(s[i] == 'P' && c) {
            ans[i] = 'S';
            cnt++;
            c--;
        } else if(s[i] == 'S' && a) {
            ans[i] = 'R';
            cnt++;
            a--;
        }
    }
    if(cnt >= (n+1)/2) {
        printf("YES\n");
        for(int i=0; i<n; i++) {
            if(ans[i] == 0) {
                if(a) {
                    ans[i] = 'R';
                    a--;
                } else if(b) {
                    ans[i] = 'P';
                    b--;
                } else if(c) {
                    ans[i] = 'S';
                    c--;
                }
            }
        }
        ans[n] = '\0';
        printf("%s\n", ans);
    } else {
        printf("NO\n");
    }
}

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        scanf("%d%d%d", &a, &b, &c);
        scanf("%s", s);
        //printf("Case #%d: %lld\n", ++kase, solve());
        solve();
    }
	return 0;
}
