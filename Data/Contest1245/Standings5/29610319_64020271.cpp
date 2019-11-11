#include <bits/stdc++.h>

using namespace std;

int t, a, b, d[100005];

bool in(int i) {
    if(d[i] == 1) return 1;

    int m = (i - b + a) % a; d[i] = 2;
    if(d[m] == 2) return 0;

    if(in(m)) {d[i] = 1; return 1;}
    else return 0;
}

void Solve() {
        scanf("%d", &t);
        while(t --) {
            scanf("%d %d", &a, &b);
            if(a > b) swap(a, b);
            b = b % a;

            for(int i = 1; i < a; ++ i) d[i] = 0;
            d[0] = 1;
            for(int i = 1; i < a; ++ i) {
                if(!in(i)) goto l1;
            }
            puts("Finite"); continue;
            l1 : puts("Infinite");
        }
}

#define task "main"
int main() {
        //freopen(task".inp","r",stdin);
        //freopen(task".out","w",stdout);
        Solve();
}
