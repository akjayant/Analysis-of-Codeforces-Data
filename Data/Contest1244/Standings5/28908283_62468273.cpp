//scnucjh
#include <iostream>
#include <map>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int n;
char s[1111];

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.txt", "r", stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        scanf("%s",s+1);
        int ans=n;
        for(int i=1;i<=n;i++) {
            if(s[i]=='1') {
                int d = max(i,n-i+1);
                ans = max(ans,d*2);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}


