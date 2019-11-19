#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;
int n, sign, pre[maxn], nxt[maxn], c[maxn], in[maxn], cl[maxn], dl[maxn], cr[maxn], dr[maxn];
char s[maxn], res[2];
long long k;

int main()
{
    scanf("%d%lld", &n, &k);
    scanf("%s", s+1);
    for(int i=1; i<=n; i++)
        if(s[i] == 'W') c[i] = 0;
        else c[i] = 1;
    res[0] = 'W';
    res[1] = 'B';
    for(int i=1; i<=n; i++) pre[i] = i-1, nxt[i] = i+1;
    nxt[n] = 1; pre[1] = n;
    for(int i=1; i<=n; i++) {//printf("%d\n", i);
        if(!in[i] && (c[i] == c[pre[i]] || c[i] == c[nxt[i]])) {
            sign = in[i] = 1;
            int t = pre[i];
            while(c[t] == c[i] && t!=i) in[t]=1, t=pre[t];
            t = nxt[i];
            while(c[t] == c[i] && t!=i) in[t]=1, t=nxt[t];
        }
    }
    for(int i=1; i<=n; i++) {//printf("%d %d %d\n", i, nxt[i], pre[i]);
        if(in[i] && c[i]!=c[nxt[i]]) {//printf(">>\n");
            int j=nxt[i], dep=0; //printf("%d\n", j);
            for(; !in[j]; j=nxt[j]) {//printf("%d\n", j);
                dep++;
                cl[j] = c[i];
                dl[j] = dep;
            }
        }
        if(in[i] && c[i]!=c[pre[i]]) {//printf("??\n");
            int j=pre[i], dep=0; //printf("%d\n", j);
            for(; !in[j]; j=pre[j]){//printf("%d\n", j);
                dep++;
                cr[j] = c[i];
                dr[j] = dep;
            }
        }
    }
    if(!sign) {
        if(k&1) {
            for(int i=1; i<=n; i++)
                if(s[i] == 'W') printf("B");
                else printf("W");
        }   else {
            printf("%s", s+1);
        }
        printf("\n");
    }   else {
        for(int i=1; i<=n; i++) {
            if(in[i]) printf("%c", s[i]);
            else {
                if(dl[i] == dr[i]) {
                    if(dl[i] > k) {
                        printf("%c", res[c[i] ^ (k&1)]);
                    }   else {
                        printf("%c", res[cl[i]]);
                    }

                }   else {
                    if(dl[i]>dr[i]){
                        swap(dl[i], dr[i]);
                        swap(cl[i], cr[i]);
                    }
                    if(dl[i] > k)
                        printf("%c", res[c[i] ^ (k&1)]);
                    else
                        printf("%c", res[cl[i]]);

                }


            }
        }
        printf("\n");
    }
    return 0;
}