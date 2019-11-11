#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;


#define ll long long
const ll mod = 1e9 + 7;

char a[105], b[105];
int n;
int main() {
    //freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        int r, p, s;
        scanf("%d%d%d", &r, &p, &s);
        scanf("%s", a);

        for(int i = 0; i < n; i++) b[i] = 0;

        int win = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == 'R' && p > 0) {
                b[i] = 'P';
                p--;
                win += 1;
            }
            if(a[i] == 'P' && s > 0) {
                b[i] = 'S';
                s--;
                win += 1;
            }
            if(a[i] == 'S' && r > 0) {
                b[i] = 'R';
                r--;
                win += 1;
            }
        }
        for(int i = 0; i < n; i++) {
            if(b[i] == 0) {
                if(r > 0) {
                    b[i] = 'R';
                    r--;
                }
                else if(p > 0) {
                    b[i] = 'P';
                    p--;
                }
                else {
                    b[i] = 'S';
                    s--;
                }
            }
        }

        if(win >= (n + 1) / 2) {
            puts("YES");
            for(int i = 0; i < n; i++) {
                printf("%c", b[i]);
            }
            puts("");
        }
        else {
            puts("NO");
        }
    }
    return 0;
}