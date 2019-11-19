#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        int a,b,c,d,e;
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
        int x=a/c+(a%c>0)+b/d+(b%d>0);
        if (x<=e) printf("%d %d\n",a/c+(a%c>0),b/d+(b%d>0));
        else printf("-1\n");
    }
    return 0;
}