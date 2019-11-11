#include <bits/stdc++.h>

using namespace std;

int t;
char s[505];
int a, b, c, n;

void draw() {
        if(a) {
            a --; cout << 'R'; return;}
        if(b) {
            b --; cout << 'P'; return;}
        if(c) {
            c --; cout << 'S'; return;}
}

void Solve() {
        scanf("%d", &t);
        while(t --) {
            scanf("%d", &n);
            scanf("%d %d %d", &a, &b, &c);
            scanf("%s", s+1);

            int A = 0, B = 0, C = 0;
            for(int i = 1; i <= n; ++ i)
                if(s[i] == 'R') B ++;
                else if(s[i] == 'P') C ++;
                else if(s[i] == 'S') A ++;

            int a1 = min(A, a);
            int b1 = min(B, b);
            int c1 = min(C, c);

            if(a1 + b1 + c1 >= (n+1)/2) {
                puts("YES");
                a -= a1; b -= b1; c -= c1;
                for(int i = 1; i <= n; ++ i) {
                    if(s[i] == 'R') {
                        if(b1) b1--, cout << 'P';
                        else draw();
                    }
                    if(s[i] == 'P') {
                        if(c1) c1--, cout << 'S';
                        else draw();
                    }
                    if(s[i] == 'S') {
                        if(a1) a1--, cout << 'R';
                        else draw();
                    }
                }
                putchar(10);
            } else
                puts("NO");
        }
}

#define task "main"
int main() {
        //freopen(task".inp","r",stdin);
        //freopen(task".out","w",stdout);
        Solve();
}
