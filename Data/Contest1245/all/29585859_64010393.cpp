#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char bo[100010];
int main()
{
    int i, j, k;
    int n, t, m;
    int a, b, c;
    cin >> t;
    while(t--) {
        scanf("%d", &n);
        scanf("%d%d%d", &a, &b, &c);
        int ba, bb, bc;
        ba = bb = bc = 0;
        getchar();
        for(i = 1; i <= n; i++) {
            scanf("%c", &bo[i]);
            if(bo[i] == 'R')
                ba++;
            else if(bo[i] == 'P')
                bb++;
            else bc++;
        }

        int da, db, dc;
        da = a - min(bc, a);
        db = b - min(ba, b);
        dc = c - min(bb, c);
        if(min(ba, b) + min(bb, c) + min(bc, a) >= (n+1)/2) {
            printf("YES\n");
            for(i = 1; i <= n; i++) {
                if(bo[i] == 'R') {
                    if(b) {
                        printf("P");
                        b--;
                    }
                    else {
                        if(da) {
                            da--;
                            printf("R");
                        }
                        else {
                            dc--;
                            printf("S");
                        }
                    }
                }
                else if(bo[i] == 'P') {
                    if(c) {
                        printf("S");
                        c--;
                    }
                    else {
                        if(da) {
                            da--;
                            printf("R");
                        }
                        else {
                            db--;
                            printf("P");
                        }
                    }
                }
                else if(bo[i] == 'S') {
                    if(a) {
                        printf("R");
                        a--;
                    }
                    else {
                        if(db) {
                            db--;
                            printf("P");
                        }
                        else {
                            dc--;
                            printf("S");
                        }
                    }
                }
            }
            printf("\n");
        }
        else puts("NO");
    }
    return 0;
}
