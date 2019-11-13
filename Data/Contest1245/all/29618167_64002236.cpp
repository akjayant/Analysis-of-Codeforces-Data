#include <bits/stdc++.h>
using namespace std;

char s1[102], s2[102];
int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int r, p, s;
        scanf("%d %d %d", &r, &p, &s);
        memset(s2, 0, sizeof(s2));
        scanf("%s", s1);
        int win = 0;
        for(int i=0; i<n; i++){
            if(s1[i] == 'S' && r)
                s2[i] = 'R', r--, win++;
            if(s1[i] == 'P' && s)
                s2[i] = 'S', s--, win++;
            else if(s1[i] =='R' && p)
                s2[i] = 'P', p--, win++;
        }
        if(win * 2 < n){
            puts("NO");
            continue;
        }
        for(int i=0; i<n; i++){
            if(s2[i] == 0){
                if(r) s2[i] = 'R', r--;
                else if(p) s2[i] = 'P', p--;
                else s2[i] ='S', s--;
            }
        }

        printf("YES\n%s\n", s2);
    }
    return 0;
}
