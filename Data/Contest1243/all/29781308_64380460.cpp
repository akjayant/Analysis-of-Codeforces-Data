#include<bits/stdc++.h>
using namespace std;
const int N = 10000 + 5;
typedef long long ll;
char s[N], t[N];
int k;
int n;
int main() {
    scanf("%d", &k);
    while(k--) {
        scanf("%d", &n);
        scanf("%s%s", s + 1, t + 1);
        int cnt = 0;
        int a1, b1, a2, b2;
        for(int i = 1; i <= n; i++) {
            if(s[i] == t[i]) continue;
            else cnt++;
            if(cnt == 1) {
                a1 = s[i];
                b1 = t[i];
            }
            if(cnt == 2) {
                a2 = s[i];
                b2 = t[i];
            }
        }
        if(cnt == 2) {
            if(a1 == a2 && b1 == b2) printf("Yes\n");
            else printf("No\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}
